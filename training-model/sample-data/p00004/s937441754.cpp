#include <iostream>
#include <iomanip>

int main(int argc, char const *argv[]){
	
	double a,b,c,d,e,f;

	while(std::cin >> a >> b >> c >> d >> e >> f){
		double y = (a*f-c*d)/(a*e-b*d);
		double x = (c-b*y)/a;
		std::cout << std::fixed << std::setprecision(3) << x << " " << y << std::endl;
	}

	return 0;
}

