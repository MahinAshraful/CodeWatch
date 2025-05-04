#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	int ns[5];
	std::cin >> ns[0] >> ns[1] >> ns[2] >> ns[3] >> ns[4];
	std::sort(ns, ns+5, std::greater<int>());
	std::cout << ns[0] << " " << ns[1] << " " << ns[2] << " " << ns[3] << " "	<< ns[4];
	std::cout << std::endl;
	return 0;
}