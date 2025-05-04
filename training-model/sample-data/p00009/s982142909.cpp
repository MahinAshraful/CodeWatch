#include<iostream>

int main(){
    int n, count = 0;
    bool isprime [1000000];
    for(int i = 0; i < 1000000; i++)
        isprime[i] = true;
    isprime[0] = isprime[1] = false;
    for(int i = 2; i <= 1000; i++){
        if(isprime[i]){
            for(int j = i * 2; j < 1000000; j += i){
                isprime[j] = false;
            }
        }
    }
    while(std::cin >> n){
        count = 0;
        for(int i = 2; i <= n; i++){
            if(isprime[i])
                count++;
        }
        std::cout << count << std::endl;
    }
}