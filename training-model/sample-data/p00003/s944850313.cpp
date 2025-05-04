#include<stdio.h>

void tri(int x, int y, int z)
{
    if((x == y + z) || (y == z + x) || (z == x + y)) {
        printf("YES\n");
    }else {
        printf("NO\n");
    }    
}

int main(void)
{
    int a, b, c, num;

    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        scanf("%d %d %d", &a, &b, &c);
        tri(a*a, b*b, c*c);
    }

    return 0;
}