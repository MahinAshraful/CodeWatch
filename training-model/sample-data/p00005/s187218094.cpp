#include<iostream>
using namespace std;

int LCG(int x, int y);

int main(){
 int a,b;
 int g;
 long l;
 while(cin >> a >> b){
    g = LCG(a,b);
    l = (long)a*b/g;
    cout << g << " " << l << endl;
 }
}

int LCG(int x, int y){
    int m = x%y;
    if(m == 0){
        return y;
    }
    LCG(y,m);
}