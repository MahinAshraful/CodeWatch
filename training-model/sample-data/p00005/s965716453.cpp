#include <iostream>

using namespace std;

int main()
{
    long long a, b;
    long long big_n, small_n, mod;
    long long GCD, LCM;

    while (cin >> a >> b)
    {
        if (a > b)
        {
            big_n = a;
            small_n = b;
        }
        else
        {
            big_n = b;
            small_n = a;
        }

        while ((mod = big_n % small_n) != 0)
        {
            big_n = small_n;
            small_n = mod;
        }

        GCD = small_n;
        LCM = (a * b) / GCD;

        cout << GCD << " " << LCM << endl;
    }

    return 0;
}

