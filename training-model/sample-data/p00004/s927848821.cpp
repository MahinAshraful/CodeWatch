#include <iostream>
#include <vector>

void solv(
	double a,
	double b,
	double c,
	double d,
	double e,
	double f,
	double & x,
	double & y){
	y = (f - (d*c)/a)/(e - (b*d)/a);
	x = (c - b*y)/a;
}

int main(){
	std::vector<std::pair<double, double>> ans;

	double a,b,c,d,e,f;
	std::pair<double, double> tmp;

	while(true){
		std::cin >> a >> b >> c >> d >> e >> f;
		if(std::cin.eof() == true) break;
		solv(a,b,c,d,e,f,
			tmp.first, tmp.second);
		ans.push_back(tmp);
	}

	for(auto && a : ans){
		printf("%0.3f %0.3f\n", a.first, a.second);
	}
}