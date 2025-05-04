#include <iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main()
{
    int  i=0,j=0;
    int a[10]={};


        for(i=0;i<10;i++){
            cin >>a[i];
        }
    sort(a,a+10);
        for(i=9;i>6;i--){
            cout << a[i] << endl;
        }


    //cout << endl;

return 0;

}