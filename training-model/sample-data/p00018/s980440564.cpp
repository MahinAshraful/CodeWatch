#include<iostream>
#include<algorithm>

int main(void){
    int a[5];
    for(int i=0;i<5;i++) std::cin>>a[i];
    std::sort(a,a+5);
    for(int i=4;i>=0;i--) std::cout<<(i==4?"":" ")<<a[i];
    std::cout<<std::endl;

    return 0;
}
