#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    double a[1010], n, s, k=0, i=0;
    cin >> n;
    for(i=0; i<n;i++){
             cin>>a[0]>>a[1]>>a[2];
             sort(a, a+3);
             k=(a[1]*a[1])+(a[0]*a[0]);
             if(a[2]==sqrt(k))
             cout<<"YES\n";
             else
             cout<<"NO\n";
    }
    return 0;
}