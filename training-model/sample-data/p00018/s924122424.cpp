#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	std::vector<int> v(5);

	for(int i=0;i<5;++i)
	{
		std::cin >> v[i];
	}

	std::sort(v.begin(),v.end());

	for(int i=4;i>0;--i)
	{
		std::cout << v[i] << ' ';
	}

	std::cout << v[0] << '\n';
}