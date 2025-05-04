#include<bits/stdc++.h>
using namespace std;
bool myfun(int a,int b){
    return a > b;
}
int main()
{
    int n;
    vector<int>vec;
    vector<int>::iterator it;
    for(int i=1;i<=10;i++){
        cin>>n;
        vec.push_back(n);
    }
    sort(vec.begin(),vec.end(),myfun);
    for(int i=0;i<3;i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}

