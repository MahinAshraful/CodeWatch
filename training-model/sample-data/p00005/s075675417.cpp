#include <iostream>
#include<stdio.h>
#define MAX_N 100005
#include<string>
typedef long long ll;
using namespace std;
ll gcd(ll a,ll b){
    if(b == 0){return a;}
    else{
        gcd(b,a%b);
    }
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);

}
int main(){
    ll a,b;
    while(cin>>a>>b){
        cout<<gcd(a,b)<<" "<<lcm(a,b)<<endl;
    }


}