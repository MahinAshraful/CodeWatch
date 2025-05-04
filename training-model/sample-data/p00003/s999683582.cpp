#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int n,A,B,C;
    cin >> n;
 
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;       
        A = a * a;
        B = b * b;
        C = c * c;
        if(A+B==C||B+C==A||C+A==B){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
