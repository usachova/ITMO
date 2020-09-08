#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char str1[100], str2[100], ch;
	char* temp;
	int n;
	scanf("%s %s %d %c", str1, str2, &n, &ch);
	
	strncat(str1, str2, n);
	printf("%s\n", str1);
	
	int k = strlen(str1);
	printf("%d\n", k);
	
	char* p = strrchr(str1, ch);
	int res = (p != NULL) ? p - str1 : 0;
	printf("%d\n", res);
	
	int l = strspn(str1, str2);
	printf("%d\n", l);
	
	char tmp[100];
	strncpy(tmp, str2, 1);
	const char* c = tmp;
	temp = strtok(str1, c);
	printf("%s\n", temp);
	
	return 0;
}
