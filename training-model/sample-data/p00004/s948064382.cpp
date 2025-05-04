#include<iostream>
#include<iomanip>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*
??£???????¨????
	ax + by = c
	dx + ey = f
????§£x, y???????????????????????°??????
*/
int main() {
	double a, b, c, d, e, f;
	int cnt = 0;						//??\??????????????£???????¨????????????°
	std::vector<double> x_vector;		//x????§£???????´?
	std::vector<double> y_vector;		//y????§£???????´?

#if 0
	while (cnt < 1) {
		cin >> a >> b >> c >> d >> e >> f;
#else
	while (cin >> a >> b >> c >> d >> e >> f) {
#endif
		if (
			(a < -1000) || (1000 < a) ||
			(b < -1000) || (1000 < b) ||
			(c < -1000) || (1000 < c) ||
			(d < -1000) || (1000 < d) ||
			(e < -1000) || (1000 < e) ||
			(a < -1000) || (1000 < f)
			) {
			break;
		}
		double x = (b * f - c * e) / (b * d - a * e);
		double y = (c * d - a * f) / (b * d - a * e);

		cnt++;
		x_vector.push_back(x);
		y_vector.push_back(y);
	}

	for (unsigned int i = 0; i < cnt; i++) {
		std::cout << std::fixed << std::setprecision(3) << x_vector[i] + 0 << " ";
		std::cout << std::fixed << std::setprecision(3) << y_vector[i] + 0 << endl;
	}

	cnt = 0;
	x_vector.clear();
	y_vector.clear();

	//???????????°
	//while (1);

	return 0;
}