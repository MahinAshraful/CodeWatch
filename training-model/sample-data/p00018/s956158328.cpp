#include <stdio.h>

int main() {
    int n[5];
    scanf("%d %d %d %d %d", &n[0], &n[1],&n[2],&n[3],&n[4]);

    {
        bool finished = false;
        while (!finished) {
            finished = true;
            for (int i = 0; i < 4; ++i) {
                if (n[i] < n[i + 1]) {
                    int temp = n[i + 1];
                    n[i + 1] = n[i];
                    n[i] = temp;
                    finished = false;
                }
            }
    }
    }

    for (int i = 0; i < 5; ++i) {
        char c = (i == 4) ? '\n' : ' ';
        printf("%d%c", n[i], c);
    }
    return 0;
}