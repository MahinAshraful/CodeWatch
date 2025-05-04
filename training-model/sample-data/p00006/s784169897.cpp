#include<cstdio>
#include<cstring>
main() {
	char str[20];

	scanf("%s", str);

	for (int i=strlen(str)-1; i >= 0; i--)printf("%c", str[i]);

	printf("\n");

	return 0;
}
