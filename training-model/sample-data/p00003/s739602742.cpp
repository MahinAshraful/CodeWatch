/*http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0003&lang=jp*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;

    cin>>n;
    for (int i = 0; i < n; ++i) {
        vector<int> lens;
        for (int j = 0; j < 3; ++j) {
            int tmp;
            cin>>tmp;
            lens.push_back(tmp);
        }
        sort(lens.begin(),lens.end(),greater<int>());
        if(pow(lens[0],2)==pow(lens[1],2)+pow(lens[2],2)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}