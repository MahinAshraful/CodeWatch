#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>vec;
int main(){
    for(int i=0;i<10;i++){
        int m;
        cin>>m;
        vec.push_back(m);
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<4;i++){
        cout<<*(vec.end()-i)<<endl;
    }
}