#include <iostream>
using namespace std;
int main()
{
    int i=0;
    int num[10];
     for(;i<10;i++)
        cin>>num[i];
     int temp=0,temp1=0,j=0,k=0;
      for(;j<3;j++) {
            for(i=0;i<10;i++)
            {
                temp1=temp;
      temp=temp<num[i]?num[i]:temp;
       if(temp>temp1)
            k=i;
       }
       cout<<num[k]<<endl;
       temp=0;
        num[k]=0;
         }
       return 0;
       }