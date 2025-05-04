#include <iostream>
using namespace std;

int main(void) {
    int stack[100];
    int tail = 0;
    int n;
    while(cin >> n) {
        if(n) {
            stack[tail++] = n;
        } else {
            cout << stack[--tail] << endl;
        }
    }
}