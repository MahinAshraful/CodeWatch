#include<iostream>
int main(){int t[31],w=1,n,a,b,c;for(;w<31;)t[w]=w++;for(std::cin>>w>>n;n--;){(std::cin>>a).ignore(1)>>b;c=t[a];t[a]=t[b];t[b]=c;}for(n=1;n<w+1;)std::cout<<t[n++]<<'\n';}