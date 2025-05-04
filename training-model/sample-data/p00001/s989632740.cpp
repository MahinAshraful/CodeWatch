#include<iostream>
using namespace std;

int main()
{
    int num = 10;
    int Mountain[num];

    for( int i = 0; i < num; i++ )
    {
        cin >> Mountain[i];
    }    

    for( int i = 0; i < num; i++ )
    {
        for( int j = 0; j < num - 1; j++)
        {
            if(Mountain[j] < Mountain[j+1] )
                {
                    int tmp = 0;
                    tmp = Mountain[j];
                    Mountain[j] = Mountain[j+1];
                    Mountain[j+1] = tmp;
                }
        }
        
    }

    for( int i = 0; i < 3; i++)
    {
        cout << Mountain[i] <<endl;
    }

    return 0;
}

