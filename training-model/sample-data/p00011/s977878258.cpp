#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
char temp;

int n,w;
int m1[40];
int main() {
    scanf("%d", &n);
    scanf("%d", &w);
    for(int i = 1; i <= n;i++)m1[i]=i;
    for(int i = 0; i < w; i++){
        int a,b;
        scanf("%d,%d", &a, &b);
        int temp = m1[b];
        m1[b] = m1[a];
        m1[a] = temp;
    }
    for(int i = 1; i <= n;i++)printf("%d\n", m1[i]);
}