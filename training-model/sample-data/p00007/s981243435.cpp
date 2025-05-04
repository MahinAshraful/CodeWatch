#include <iostream>
using namespace std;

int main()
{
  int debt=100000;
  double interest=1.05;
  int week=0;

  cin>>week;

  for(int i=0;i<week;i++){
    debt*=interest;
    if(debt%1000!=0){
      debt-=debt%1000;
      debt+=1000;
    }
  }

  cout<<debt<<endl;

  return 0;
}

