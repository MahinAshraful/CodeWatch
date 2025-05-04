#include <iostream>
#include <stack>

using namespace std;

int main() {
    int x;
    stack<int> stack;

    while (cin >> x) {
        if (!x) {
            cout << stack.top() << endl;
            stack.pop();
        } else {
            stack.push(x);
        } 
    }
}