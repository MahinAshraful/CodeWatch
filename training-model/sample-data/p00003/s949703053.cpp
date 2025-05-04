#include <stdio.h>

void right_triangle (int x, int y, int z)
{
    if(x * x == y * y + z * z || y * y == z * z + x * x || z * z == x * x + y * y){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        right_triangle(x, y, z);
    }
    return 0;
}