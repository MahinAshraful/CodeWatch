#include <iostream>
using namespace std;
#define LL long long
LL gcd(LL a,LL b){
    LL t;
    while(a%b){
        t = a;
        a = b;
        b = t%b;
    }
    return b;
}
int main() {
    LL a,b;
    while(cin>>a>>b){
        LL G = gcd(a,b);
        LL L = a/G * b;
        cout<<G<<" "<<L<<endl;
    }
    return 0;
}

