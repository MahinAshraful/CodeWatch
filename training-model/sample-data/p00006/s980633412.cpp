#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(void) {
    string input; cin >> input;
    reverse(input.begin(), input.end());
    cout << input << endl;
    return(0);
}