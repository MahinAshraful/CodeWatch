#include <iostream>
#include <vector>

int main()
{
	std::vector<int> cars;
	int input;
	while (std::cin >> input) {
		if (input != 0) {
			cars.push_back(input);
		} else if (!cars.empty()) {
			std::cout << cars.back() << std::endl;
			cars.pop_back();
		}
	}

	return 0;
}