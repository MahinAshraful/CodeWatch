#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int input[5];

    for (int i = 0; i < 5; i++)
        cin >> input[i];

    sort(input, input + 5, greater<int>());

    cout << input[0] << " " << input[1] << " " << input[2] << " " << input[3];
    cout << " " << input[4] << endl;


    return 0;
}