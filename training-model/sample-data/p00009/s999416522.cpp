#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1000000;
vector <int> primeCountList(MAX, 0);//indx:number value:primeCount

void setPrimeCount()
{
    int primeCount = 1;
    for(int i=3;i<=MAX;i+=2)
    {
        bool isPrime = true;
        for(int j=3;j*j<=i;j+=2)
        {
            if(i%j == 0)
            {
                isPrime = false;
                break;
            }
        }
        primeCountList[i-1] = primeCount;
        if(isPrime)
        {
            primeCount++;
            primeCountList[i] = primeCount;

        }
        else
        {
            primeCountList[i] = primeCount;
        }

    }
    primeCountList[2] = 1;

}
/*
 * getPrimeNumber:0009
 */
int main()
{
    setPrimeCount();
    int n;
    while(cin >> n)
    {
        cout << primeCountList[n] << endl;
    }
    return 0;
}