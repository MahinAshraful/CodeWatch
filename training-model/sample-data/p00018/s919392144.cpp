#include<iostream>

int main(){
	int a[5],i,n,j;
	
	for(i=0;i<5;i++){
	std::cin>>a[i];
	}
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(a[i]<a[j]){
				n=a[i];
				a[i]=a[j];
				a[j]=n;
				}
			}
		}
	for(i=0;i<4;i++){
	std::cout<<a[i]<<" ";
	}	
	
	std::cout<<a[4];
	
	std::cout<<std::endl;
	
	return 0;
	
	}