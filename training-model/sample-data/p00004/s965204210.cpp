#include <iostream>
#include <cmath> 

auto main () -> int
{
    static const char * zeros [] = {"00" , "00" , "0" , ""};
    double a , b , c , d , e , f;
    while (std::cin >> a >> b >> c >> d >> e >> f)
    {
        auto delta = a * e - b * d;
        auto x = (e * c - b * f) / delta;
        auto y = (- c * d + a * f) / delta;
        auto x_ = std::lround (x * 1000);
        auto y_ = std::lround (y * 1000);
        auto x_high = x_ / 1000;
        auto x_low = std::abs (x_) % 1000;
        auto y_high = y_ / 1000;
        auto y_low = std::abs (y_) % 1000;
        std::cout << x_high << '.' << x_low << zeros [x_low ? static_cast <int> (std::log10 (x_low)) + 1 : 0] << ' '
                  << y_high << '.' << y_low << zeros [y_low ? static_cast <int> (std::log10 (y_low)) + 1 : 0] << std::endl;
    }
}