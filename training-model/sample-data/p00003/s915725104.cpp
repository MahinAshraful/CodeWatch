#include <stdio.h>

int main() {
    const char YES[] = "YES\n";
    const char NO[] = "NO\n";

    int times = 0;
    scanf("%d", &times);
    for (int i = 0; i < times; ++i) {
        int inputSide[3];
        scanf("%d %d %d", &inputSide[0], &inputSide[1], &inputSide[2]);
        {
            bool finished = false;
            while (!finished) {
                finished = true;

                for (int j = 0; j < 3 - 1; ++j) {
                        if (inputSide[j] < inputSide[j + 1]) {
                        int temp = inputSide[j + 1];
                        inputSide[j + 1] = inputSide[j];
                        inputSide[j] = temp;
                        finished = false;
                    }
                }
            }
        }

        printf(((((inputSide[2] * inputSide[2]) + (inputSide[1] * inputSide[1])) == (inputSide[0] * inputSide[0])) ? YES : NO));
    }

    return 0;
}