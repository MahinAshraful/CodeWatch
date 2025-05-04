#include<iostream>
#include<cmath>

using namespace std;

int main() {
        int t, a, b, c;
        cin>>t;
        for(int i; i<t; i++) {
                cin>>a>>b>>c;
                int ax = pow(a, 2);
                int bx = pow(b, 2);
                int cx = pow(c, 2);
                if(ax+bx==cx || bx+cx==ax || ax+cx==bx) cout << "YES" << endl;
                else cout << "NO" << endl;
        }
        return 0;
}