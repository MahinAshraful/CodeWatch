#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>

int main(){
	char str[20];
	gets(str);
	for (int i = strlen(str) - 1; i >= 0; i--)
		printf("%c", str[i]);
	printf("\n");
	return 0;
}