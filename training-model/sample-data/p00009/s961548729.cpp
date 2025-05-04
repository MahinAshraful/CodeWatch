#include<iostream>
#include<cmath>
using namespace std;

//素数かどうか判定する関数
bool judge( int x )
{

    for( int i = 2; i <= sqrt(x); i++ )       //与えられた数が10なら
    {                                         //
        if( x % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;

    while( cin >> n )                           
    {
        bool PN[n+1];                           //PrimeNumber
        int count = 0;                          //countは素数の数


        PN[0] = false;                          //0は素数ではない。
        PN[1] = false;                          //1は素数ではない。

        for( int i = 2; i <= n; i++)            //0,1以外の全ては素数候補。ここから篩にかける。 
        {
            PN[i] = true;                       //ex.100の場合、2~100を素数候補とする
            count++;
        }

        for( int i = 2; i <= sqrt(n); i++)            
        {
            for( int j = 2; j <= n / i; j++ )
            {
                if( PN[i*j] == true )
                {
                    PN[i*j] = false;
                    count--;
                }

            }
        }
        cout << count << endl;
    }

    return 0;
}
