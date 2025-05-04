#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

void Sort()
{
    int a[5];
    
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
        
    sort (a, a + 5, greater<int>()); //sorting from big int
        
    for(int i = 0; i < 4; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout<<a[4]<<endl;  //don't forget this part
    
    return;
}

int main()
{
    Sort();
    return 0;
}