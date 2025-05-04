#include<iostream>
#include<cstdio>
using namespace std;


main(){
  int a[31],b[31];
  int w,n;
  int num[31]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
	       21,22,23,24,25,26,27,28,29,30};
  int temp;
  
  while(cin >> w){
    
    cin >> n;

    for(int i=1;i<=n;i++){
      //      cin >> a[i] >> ,>>b[i];
      scanf("%d,%d",&a[i],&b[i]);
    }

    for(int i=1;i<=n;i++){
      temp = num[a[i]];
      num[a[i]] =num[b[i]];
      num[b[i]] = temp;
    }

    for(int i=1;i<=w;i++){
      cout << num[i] << endl;
    }
  
  }



  
  return 0;

}