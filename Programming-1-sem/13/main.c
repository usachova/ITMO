#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef union {
    char buffer[12];
    struct {
        unsigned short empty;
        unsigned char version[3];
        unsigned char v1;
        unsigned char v2;
        unsigned char flags;
        unsigned int size;
    } data;
} TAGHEADER;

typedef union {
    char buffer[10];
    struct {
        unsigned char name[4];
        unsigned int size;
        unsigned short flags;
    } data;
} FRAMEHEADER;

unsigned int reverseBytes(unsigned int n) {
    return ((n >> 24) & 0x000000ff) | ((n >> 8) & 0x0000ff00) | ((n << 8) & 0x00ff0000) | ((n << 24) & 0xff000000);
}

void copyFile(FILE* inp, FILE* outp) {
    int c;
    while ((c = getc(inp)) != EOF)
        putc(c, outp);
}

void show(char* fileName) {
    FILE* file;
    file = fopen(fileName, "rb");
    fseek(file, 0, SEEK_SET);
    TAGHEADER tagHeader;
    fread(tagHeader.buffer + 2, sizeof(char), 10, file);
    unsigned int tagSize = reverseBytes(tagHeader.data.size);
	printf("%sv%d.%d\n", tagHeader.data.version, tagHeader.data.v1, tagHeader.data.v2);
    while (ftell(file) < tagSize + 10) {
        FRAMEHEADER frameHeader;
        fread(frameHeader.buffer, sizeof(char), 10, file);
        if (frameHeader.data.name[0] == 0)
            break;
        printf("%s: ", frameHeader.data.name);
        unsigned int frameSize = reverseBytes(frameHeader.data.size);
        unsigned char* frameContent;
        frameContent = malloc(sizeof(char) * frameSize);
        fread(frameContent, sizeof(char), frameSize, file);
        for (int i = 0; i < frameSize; ++i) {
            printf("%c", frameContent[i]);
        }
        printf("\n");
        free(frameContent);
    }
    fclose(file);
}

void set(char* fileName, char frameName[4], char* frameValue) {
    FILE* file;
    file = fopen(fileName, "rb");
    TAGHEADER tagHeader;
    fread(tagHeader.buffer + 2, sizeof(char), 10, file);
    unsigned int tagSize = reverseBytes(tagHeader.data.size);
    unsigned int oldFramePos = 0;
    unsigned int oldFrameSize = 0;
    while (ftell(file) < tagSize + 10) {
        FRAMEHEADER frameHeader;
        fread(frameHeader.buffer, sizeof(char), 10, file);
        unsigned int frameSize = reverseBytes(frameHeader.data.size);
        if (strcmp(frameHeader.data.name, frameName) == 0) {
            oldFramePos = ftell(file) - 10;
            oldFrameSize = frameSize;
            break;
        }
        fseek(file, frameSize, SEEK_CUR);
    }
    unsigned int valueSize = strlen(frameValue);
    unsigned int newTagSize = tagSize - oldFrameSize + valueSize + 10 * (oldFramePos != 0);
    if (oldFramePos == 0) oldFramePos = ftell(file);
    if (valueSize == 0) newTagSize -= 10;
    FILE* fileCopy;
    fileCopy = fopen("tmp.mp3", "wb");
    fseek(file, 0, SEEK_SET);
    fseek(fileCopy, 0, SEEK_SET);
    copyFile(file, fileCopy);
    fclose(file);
    fclose(fileCopy);
    fileCopy = fopen("tmp.mp3", "rb");
    file = fopen(fileName, "wb");
    tagHeader.data.size = reverseBytes(newTagSize);
    fwrite(tagHeader.buffer + 2, sizeof(char), 10, file);
    fseek(fileCopy, 10, SEEK_SET);
    for (int i = 0; i < oldFramePos - 10; ++i) {
        int c;
        c = getc(fileCopy);
        putc(c, file);
    }
    if (valueSize > 0) {
        FRAMEHEADER frameHeader;
        for (int i = 0; i < 4; ++i) {
            frameHeader.data.name[i] = frameName[i];
        }
        frameHeader.data.size = reverseBytes(valueSize);
        frameHeader.data.flags = 0;
        fwrite(frameHeader.buffer, sizeof(char), 10, file);
    }
    fwrite(frameValue, sizeof(char), valueSize, file);
    fseek(fileCopy, oldFramePos + 10 + oldFrameSize, SEEK_SET);
    for (int i = ftell(file); i < newTagSize; ++i) {
        unsigned short int c;
        c = getc(fileCopy);
        putc(c, file);
    } 
    copyFile(fileCopy, file);
    fclose(file);
    fclose(fileCopy);
    remove("tmp.mp3");
}

void get(char* fileName, char frameName[4]) {
    FILE* file;
    file = fopen(fileName, "rb");
    TAGHEADER tagHeader;
    fread(tagHeader.buffer + 2, sizeof(char), 10, file);
    unsigned int tagSize = reverseBytes(tagHeader.data.size);
    while (ftell(file) < tagSize + 10) {
        FRAMEHEADER frameHeader;
        fread(frameHeader.buffer, sizeof(char), 10, file);
        unsigned int frameSize = reverseBytes(frameHeader.data.size);
        if (strcmp(frameHeader.data.name, frameName) == 0) {
            printf("%s: ", frameHeader.data.name);
            unsigned char* frameContent;
            frameContent = malloc(sizeof(char) * frameSize);
            fread(frameContent, sizeof(char), frameSize, file);
            for (int i = 0; i < frameSize; ++i) {
                printf("%c", frameContent[i]);
            }
            printf("\n");
            free(frameContent);
            fclose(file);
            return;
        }
        fseek(file, frameSize, SEEK_CUR);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
	char* fileName;
    fileName = strpbrk(argv[1], "=") + 1;
	if (argv[2][3] == 'h') { //show
		show(fileName);
	}
	if (argv[2][2] == 's' && argv[2][3] == 'e') { //set
		char* frameName;
    	char* value;
		frameName = strpbrk(argv[2], "=") + 1;
		value = strpbrk(argv[3], "=") + 1;
		set(fileName, frameName, value);
	}
	if (argv[2][2] == 'g') { //get
		char* frameName;
		frameName = strpbrk(argv[2], "=") + 1;
		get(fileName, frameName);
	}
	return 0;
}
