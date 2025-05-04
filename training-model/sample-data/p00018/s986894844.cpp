#include <iostream>


void swap(int &a, int &b)
{
	int c = a;
	a = b; b = c;
	return;
}

int main(void)
{
	int n[5]={0,0,0,0,0};
	for(int i=0; i < 5; i++){
		std::cin >> n[i];
		for(int j=0; i-j > 0; j++)
			if(n[i-j] > n[i-j-1])
				swap(n[i-j] , n[i-j-1]);
	}
	std::cout << n[0] << " ";
	std::cout << n[1] << " ";
	std::cout << n[2] << " ";
	std::cout << n[3] << " ";
	std::cout << n[4] << std::endl;
	return 0;
}