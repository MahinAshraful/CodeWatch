#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int w,n;
    cin >> w;
    cin >> n;

    int a[30];
    for (int i = 0; i < w; ++i) {
        a[i] = i + 1;
    }

    while (n--) {
        int i,j;
        scanf("%d,%d", &i, &j);
        swap(a[i-1], a[j-1]);
    }

    for (int i = 0; i < w; ++i) {
        cout << a[i] << "\n";
    }

    return 0;
}