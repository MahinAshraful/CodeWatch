#include <stdio.h>

int main() {
    int weeks = 0;
    double money = 100.0d;
    scanf("%d", &weeks);

    for (int i = 0; i < weeks; ++i) {
        money *= 1.05d;
        int temp = (int) money;
        if (temp < money) {
            temp++;
        }
        money = temp;
    }

    int result = (int) money;
    result *= 1000;
    printf("%d\n", result);

    return 0;
}