#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char s[24];
    cin.getline(s, 24);
    int n = cin.gcount()-1;
    for(int i=n-1; i>=0; --i) cout<<s[i];
    cout<<'\n';
    return 0;
}