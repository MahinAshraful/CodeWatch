#include<iostream>
using namespace std;

int main () {
    int i, m1,m2,m3,h[10];
    for(i=0;i<10;i++)
        cin >> h[i];
    for(i=0;i<10;i++) {
        if(h[i]>=m1) {m3=m2;m2=m1;m1=h[i];}
        else if(h[i]<m1&&h[i]>=m2) {m3=m2;m2=h[i];}
        else if(h[i]<m2&&h[i]>=m3) {m3=h[i];}
    }
    cout << m1 << endl;
    cout << m2 << endl;
    cout << m3 << endl;
}