#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int a[5];
    for (int i = 0; i < 5; ++i)
        cin >> a[i];
    sort(a, a + 5);
    for (int i = 4; 0 <= i; --i)
        cout << ((i!=4)? " ": "") << a[i];
    cout << endl;
    return 0;
}




