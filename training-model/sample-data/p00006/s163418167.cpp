#include<iostream>
#include<array>
#include<algorithm>

int main(){
	std::array<char, 20>str;
	
	for(int i=0; i<20; ++i){
		std::cin >> str[i];
	}
	
	for(int i=str.size()-1; i>=0; --i){
		std::cout << str[i];
	}
	std::cout << std::endl;
	return 0;
}