#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
    stack<int> unforwardable;
    vector<int> output;
    int car;
    while(cin >> car) {
        if(car == 0) {
            output.push_back(unforwardable.top());
            unforwardable.pop();
        } else {
            unforwardable.push(car);
        }
    }
    vector<int>::iterator ite;
    for(ite = output.begin(); ite != output.end(); ite++) {
        cout << *ite << endl;
    }
    return(0);
}