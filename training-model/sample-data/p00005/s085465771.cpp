#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long ULL;

inline ULL GCD(ULL a,ULL b)
{
    ULL res=0;
    if(a != b)
    {
        if(a > b) 
        {
            if(a % b == 0)
            {
                return b;
            }
            else
            {
                GCD(b,(a % b));
            }

        }
        else 
        {
            if(b % a == 0)
            {
                return a;
            }
            else
            {
                GCD(a,(b % a));
            }

        }
    }
    else
    {
        return a;
    }
}
inline ULL LCM(ULL a,ULL b)
{
    ULL l  = GCD(a,b);
    ULL l1 = a / l;
    ULL l2 = b / l;
    return l * l1 * l2;
}
int main()
{
    ULL a,b;
    while(cin >> a >> b)
    {
        cout << GCD(a,b) << " " << LCM(a,b) << endl;
    }
    return 0;
}