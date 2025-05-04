#include <bits/stdc++.h>

int main(){
    int n,a,b,c,max;
    bool output[1000]={false};

    std::cin >> n;
    for (int i=0;i<n;++i)
    {
        std::cin >> a >> b >> c;
        if (a>b && a>c){
            max = a;
            a = 0;
        }
        else if (b>a && b>c){
            max= b;
            b = 0;
        }
        else if (c>a && c>b){
            max= c;
            c = 0;
        }
        if (pow(max,2) == pow(a,2)+pow(b,2)+pow(c,2)){
            output[i] = true;
        }
    }
    for (int i=0;i<n;++i){
        if (output[i]) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
}