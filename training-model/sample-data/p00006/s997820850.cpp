#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int j, i=0;
  char str[25], rts[25];
  cin >> str ;
  while(1){
    if(str[i]=='\0'){
      break;
    }
    i++;
  }

  
  for(j=0;i>0;j++){
    rts[j]=str[i-1];
    i--;
  }
  rts[j]='\0';
  
  cout << rts << endl;
  return 0;
}