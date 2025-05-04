#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int num[3],n;
cin>>n;
for(int i=0;i<n;i++){
cin>>num[0]>>num[1]>>num[2];
sort(num,num+3);
  if(num[0]*num[0]+num[1]*num[1]==num[2]*num[2]){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
 
 
return 0;
}