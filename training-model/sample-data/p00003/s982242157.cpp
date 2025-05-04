#include <bits/stdc++.h>

using namespace std;

int N;
int sides[3];

bool rtt(int* arr){
    for(int i = 0; i < 3; i++){
        if(arr[i] * arr[i] == arr[(i + 1) % 3] * arr[(i + 1) % 3] + arr[(i + 2) % 3] * arr[(i + 2) % 3]){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> sides[0] >> sides[1] >> sides[2];
        if(rtt(sides)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}