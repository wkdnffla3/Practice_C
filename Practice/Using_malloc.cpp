#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	char buf[256];
	char *str;
	str = (char *)malloc(sizeof(char) * 10);
	
	strcpy(str, "abcdefg");
	for (;;) {
		scanf("%s",buf);
		str = (char *)realloc(str, strlen(buf));
		strcpy(str, buf);
		printf("%s\n",buf);
	}
	free(str);
	return 0;
}