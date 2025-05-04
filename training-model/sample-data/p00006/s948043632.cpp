#include<iostream>
#include<cstring>
#include<string>

int main(){
	std::string str;
	std::cin >> str;

	for(int i = str.length()-1; i >= 0 ; --i)
		std::cout << str.at(i);

	std::cout << std::endl;


  return 0;
}