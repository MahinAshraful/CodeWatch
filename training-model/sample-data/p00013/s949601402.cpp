#include <cstdio>

using namespace std;

int main()
{
	int in[10];
	int i = 0;

	while (scanf("%d", &in[i]) != EOF){
		if (in[i] == 0){
			i--;
			printf("%d\n", in[i]);
		}
		else {
			i++;
		}
	}
}