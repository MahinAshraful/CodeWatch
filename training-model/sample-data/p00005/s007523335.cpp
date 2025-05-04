#include<iostream>
#include<stdio.h>

using namespace std;

int max(int x, int y){
        int r;

        while((r = x % y) != 0){
                x = y;
                y = r;
        }
        return y;
}

long long int small(long long int x,long long  int y, int r){
        if(x * y % r  == 0)
                return x * y / r;
        else
                return x * y;
}       

int main(){
        int x,y,r;

        while((scanf("%ld %ld",&x,&y)) != EOF){
                if(x < y){
                        int num = y;
                        y = x;
                        x = num;
                } 
                cout << max(x,y) << " " << small(x,y,max(x,y)) << endl;
        }
}