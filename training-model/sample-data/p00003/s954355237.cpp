#include <iostream>
using namespace std;
bool judge(int,int,int);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if (judge(a, b, c)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}

bool judge(int a, int b, int c){
    if (a > b && a > c && a * a == b * b + c * c){
        return true;
    }else if(b > a && b > c && b * b == c * c + a * a){
        return true;
    }else if(c > a && c > b && c * c == a * a + b * b){
        return true;
    }else{
        return false;
    }
}