#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int n,debt=100000;
    cin >> n;
    for(int i=0;i<n;i++){
        debt*=1.05;
        if((debt-(debt/1000)*1000)>0){
            debt=(debt/1000 + 1)*1000;
        }
    }
    cout << debt << endl;
    return 0;
}