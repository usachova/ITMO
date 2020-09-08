#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dir.h>

struct bmp {
    int width;
    int height;
    int size;
};

void game(int** world, int height, int width) {
	int prev[height][width];
	for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
        	prev[i][j] = world[i][j];
        }
	}
    for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
            int live_nb = world[i - 1][j - 1] + world[i][j - 1] + world[i + 1][j - 1] + world[i - 1][j] + world[i + 1][j] + world[i + 1][j + 1] + world[i][j + 1] + world[i - 1][j + 1];
			if (prev[i][j] == 0) {
                if (live_nb == 3) prev[i][j] = 1;
            } 
			else {
                if (live_nb < 2 || live_nb > 3) prev[i][j] = 0;
                else prev[i][j] = 1;
            }
        }
	}
	int cnt = 0;
	for (int i = 1; i < height - 1; i++) {
        for (int j = 1; j < width - 1; j++) {
        	if (prev[i][j] == world[i][j]) cnt++;
        	world[i][j] = prev[i][j];
        }
	}
	if (cnt == height * width) exit(0);
}

int main(int argc, char *argv[]) {
	struct bmp image;
    unsigned char header[54];
    int maxiter = 1000000, dumpfreq = 1;
    char* dirname;
    FILE* file;

    for(int i = 0; i < argc; i++){
        if(!strcmp("--input", argv[i])){
            file = fopen(argv[i + 1], "rb");
        }
        if(!strcmp("--output", argv[i])){
            dirname = argv[i + 1];
            mkdir(dirname);
        }
        if(!strcmp("--max_iter", argv[i])){
            maxiter = strtol(argv[i + 1], 0, 10);
        }
        if(!strcmp("--dump_freq", argv[i])){
            dumpfreq = strtol(argv[i + 1], 0, 10);
        }
    }
	
	fread(header, 1, 54, file);
    image.width = header[21] * 256 * 256 * 256 + header[20] * 256 * 256 + header[19] * 256 + header[18];
    image.height = header[25] * 256 * 256 * 256 + header[24] * 256 * 256 + header[23] * 256 + header[22];
    image.size = header[5] * 256 * 256 * 256 + header[4] * 256 * 256 + header[3] * 256 + header[2];
    unsigned char imagebyte[image.size - 54];
    fread(imagebyte, 1, image.size, file);
    
	int** world = (int**)malloc(image.height * sizeof(int*));
    for(int i = 0; i < image.height; i++)
        world[i] = (int*)malloc(image.width * sizeof(int));
	   
    int k = -(image.width % 4);
    for(int i = image.height - 1; i >= 0; i--){
        k += (image.width % 4);
        for(int j = 0; j < image.width; j++){
            if(imagebyte[k] == 255)
                world[i][j] = 0;
            else
                world[i][j] = 1;
            k += 3;
        }
    }
    
    int livepoints = -1;
    int isopt = 0;
    int l = 0;
    while (l <= maxiter && livepoints != 0 && isopt == 0) {
        if(l % dumpfreq == 0) {
            char filename[l];
            char way[20];
            strcpy(way, dirname);
            strcat(strcat(way, "\\"), strcat(itoa(l, filename, 10), ".bmp"));
            FILE* life = fopen(way, "w");
            fwrite(header, 1, 54, life);
            int m = 0;
            for (int i = image.height - 1; i >= 0; i--){
                for (int j = 0; j < image.width; j++){
                    for (int k = 0; k < 3; k++) {
                        if (world[i][j] == 1)
                            imagebyte[m] = 0;
                        else
                            imagebyte[m] = 255;
                        m++;
                    }
                }
                while (m % 4 != 0) {
                    imagebyte[m] = 0;
                    m++;
                }
            }
            fwrite(imagebyte, 1, image.size, life);
            fclose(life);
    	}
        game(world, image.height, image.width);
        l++;
	}
	
    return 0;
}
