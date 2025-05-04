#include <iostream>
#include <vector>
#include <algorithm>
	

unsigned isPrime(unsigned x) {
	static std::vector<unsigned> primes{2};
	if (x < 2) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	if (primes.back() < x) {
		for (unsigned i = primes.back() + 1; i*i <= x; i++) {
			bool isPrime = std::none_of(primes.begin(), primes.end(), [i](auto d){ return i % d == 0; });
			if (isPrime) {
				primes.push_back(i);
			}
		}
	}
	bool isPrime{true};
	for (auto&& var : primes) {
		if (var >= x) break;
		if (x % var == 0) {
			isPrime = false;
			break;
		}
	}
	return (isPrime) ? 1 : 0;
}

unsigned numOfPrime(const unsigned& x) {
	unsigned sum{};
	static unsigned ntable[999999]{};
	static unsigned maxX{1};
	if (x < 2) {
		return 0;
	}
	if (x == 2) {
		return 1;
	}
	unsigned count_from = std::min(maxX, x);
	sum += ntable[count_from];
	for (unsigned i = count_from + 1; i <= x; i++) {
		sum += isPrime(i);
		ntable[i] = sum;
	}
	maxX = std::max(x,maxX);
	return sum;
}

int main(int argc, char const* argv[])
{
	unsigned d{};
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while (std::cin >> d) {
		std::cout << numOfPrime(d) << std::endl;
	}
	return 0;
}