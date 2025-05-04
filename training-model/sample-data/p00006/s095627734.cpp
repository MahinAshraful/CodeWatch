
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
    
#define ll (long long)
#define REP(i,n) for(int i = 0;i<(int)n;i++)
#define FOR(i,a,b) for(int i = (a);i < (b);i++)
#define RFOR(i,a,b) for(int i = (a);i>(b);i--)


using namespace std;


int main(void)
{
    char str[30] = {};
    char temp;
    int size = 0;
    gets(str);
    while(*(str+size))
        size++;
    RFOR(i, size-1,-1)
    cout << *(str+i);
    cout << endl;
    return 0;
    

    }