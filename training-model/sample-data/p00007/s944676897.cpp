#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    double debt = 100.0;

    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        debt = ceil(debt * 1.05);
    }
    cout << static_cast<int>(debt * 1000) << endl;

    return 0;
}