#include <iostream>			//std::cout, std::cin
#include <string>			//std::string,std::to_string(C++11)
#include <vector>			//std::vector
#include <valarray>			//std::valarray
#include <algorithm>		//std::sort
#include <ctime>			//localtime_s
#include <cstdlib>			//abs
#include <cmath>			//abs,std::pow,sqrt,sin,cos,round,floor,ceil
#include <fstream>			//std::ifstream,std::ofstream
#include <iomanip>			//std::setprecision,std::setw,std::setfill
#include <random>			//std::random(C++11)
#include <numeric>			//std::accumulate
#include <functional>		//std::greater
#include <chrono>			//std::chrono(C++11)
#include <bitset>			//std::bitset
#include <queue>			//std::queue

const static double	de_PI	= 3.14159265358979323846;
const static int	de_MOD	= 1000000007;
const static int	de_MAX	= 999999999;

double RoundOff(double a, const int n) {

	for (int i = 0; i < n - 1; i++) {	a *= 10;	}

	if (a > 0) {	a += 0.5;	}
	else {			a -= 0.5;	}

	a = static_cast<int>(a);

	for (int i = 0; i < n - 1; i++) {	a /= 10;	}

	return a;
}

int main(void) {

	//std::ifstream in("123.txt");	std::cin.rdbuf(in.rdbuf());
	//std::ofstream ofs("456.csv");
	//std::chrono::system_clock::time_point t_st = std::chrono::system_clock::now();

	double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
	std::vector<double> X, Y;

	while (std::cin >> a) {
		std::cin >> b >> c >> d >> e >> f;
		X.push_back(RoundOff((b*f - c*e) / (b*d - a*e), 4));
		Y.push_back(RoundOff((a*f - c*d) / (a*e - b*d), 4));
	}

	for (unsigned int i = 0; i < X.size(); i++) {
		std::cout << std::fixed << std::setprecision(3) << X[i] << " " << Y[i] << std::endl;
	}

	//std::chrono::system_clock::time_point t_ed = std::chrono::system_clock::now();
	//std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t_ed - t_st).count() << "ms" << std::endl;

}