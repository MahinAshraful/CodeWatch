#include <iostream>
#include <algorithm>
using namespace std;

#define LEN 10

int main() {

    int hills[LEN] = {0};
    for (int i = 0; i < LEN; ++i) {
        cin >> hills[i];
    }

    sort(hills, hills + LEN);

    cout << hills[9] << endl;
    cout << hills[8] << endl;
    cout << hills[7] << endl;

    return 0;
}