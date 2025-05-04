#include<iostream>
#include<algorithm>
int x[10];
int main(){
	for(int i=0;i<10;++i){
		std::cin>>x[i];
	}
	std::sort(std::begin(x),std::end(x));
	for(int i=0;i<3;++i){
		std::cout<<x[9-i]<<std::endl;
	}
	return 0;
}