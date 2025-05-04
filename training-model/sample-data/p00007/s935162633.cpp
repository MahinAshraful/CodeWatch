#include <iostream>
#include <cmath>

int main() {
    int n;
    double m = 100000.;
    long long int part;
    std::cin >> n;

    for (;n--;) {
        m *= 1.05;
        m = std::floor(m);
        part = (long long int )m % 1000;
        if (part > 0) {
            m += 1000. - (double)part;
        }
    }

    std::cout << (long long int) m << std::endl;

    return 0;
}