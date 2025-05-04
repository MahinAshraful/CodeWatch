#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
  vector<int> data;

  for(int i=0;i<10;i++)
  {
    int input;
    cin>>input;
    data.push_back(input);
  }
  
  sort(data.begin(),data.end(),greater<int>());

  for(int i=0;i<3;i++)
  {
    cout<<data[i]<<endl;
  }
}