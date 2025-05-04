#include <iostream>

using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    return b>0?gcd(b,a%b):a;
}
ll lcm(ll a,ll b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    ll a,b;
    while ((cin>>a>>b)>0)
    {
        ll GCD=gcd(a,b);
        cout<<GCD<<" "<<a/GCD*b<<endl;
    }
    return 0;
}