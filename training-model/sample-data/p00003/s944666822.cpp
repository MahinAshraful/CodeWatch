#include <iostream>

int triangle(int x, int y, int z)
{
	int a = x * x;
	int b = y * y;
	int c = z * z;
	return (a + b - c) * (b + c - a) * (c + a - b);
}

int main()
{
	int N, x, y, z;
	
	std::cin >> N;
	
	for(int i = 0; i < N; i++){
		std::cin >> x >> y >> z;
		if ( triangle(x, y, z) == 0 ){
			std::cout << "YES" << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}