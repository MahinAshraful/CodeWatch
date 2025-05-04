#include <cstdio>

int main()
{
    int amida[33];
    for (int i = 0; i <= 31; ++i)
        amida[i] = i;
    int w, n;
    int a, b;
    std::scanf("%d %d", &w, &n);
    for (int i = 0; i < n; ++i) {
        std::scanf("%d,%d", &a, &b);
        amida[32] = amida[a];
        amida[a] = amida[b];
        amida[b] = amida[32];
    }
    for (int i = 1; i <= w; ++i)
        std::printf("%d\n", amida[i]);
}

