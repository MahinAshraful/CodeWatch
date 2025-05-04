#include<iostream>
#include<string.h>
#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<map>
#include<stack>
#include<queue>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug " << x << endl;
using namespace std;

int main(){
    int input;
    stack<int> cars;
    while(cin >> input){
        if(input > 0){
            cars.push(input);
        }else{
            cout << cars.top() << endl;
            cars.pop();
        }
    }
}