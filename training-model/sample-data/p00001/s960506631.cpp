# include <algorithm>
# include <iostream>
# include <functional>

int m[10];

int main() {
	for (int i = 0; i < 10; ++i)
		std::cin >> m[i];
	std::sort(m, m + 10, std::greater<int>());
	for (int i = 0; i < 3; ++i)
		std::cout << m[i] << std::endl;
	return 0;
}