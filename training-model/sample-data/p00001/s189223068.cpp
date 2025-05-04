#include <vector>
#include <cstdio>
#include <algorithm>

namespace
{
	std::vector<unsigned int> altitude(10);
}

int main()
{
	for (unsigned int i = 0; i < 10; i++)
	{
		std::scanf("%u", &altitude[i]);
	}
	std::sort(altitude.begin(), altitude.end(), std::greater<unsigned int>());
	for (unsigned int i = 0; i < 3; i++)
	{
		std::printf("%u\n", altitude[i]);
	}
}
