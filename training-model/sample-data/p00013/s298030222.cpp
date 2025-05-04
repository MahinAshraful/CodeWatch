
#include <iostream>
#include <stack>

int car_n;
std::stack<int> st;

bool get_input()
{
	return (std::cin >> car_n);
}

int main()
{
	while (get_input()) {
		if (car_n == 0) {
			std::cout << st.top() << std::endl;
			st.pop();
		} else {
			st.push(car_n);
		}
	}
	return 0;
}