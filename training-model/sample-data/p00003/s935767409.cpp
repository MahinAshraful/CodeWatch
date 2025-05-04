#include <iostream>

int IIRT(int a, int b, int c);

int main()
{
    int n;
    std::cin >> n;
    for (int i=0; i<n; i++) {
        int a,b,c;
        std::cin >> a >> b >> c;
        if (IIRT(a,b,c)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO"  << std::endl;
        }
    }
}

int IIRT(int a, int b, int c)
{
    if ((a*a + b*b) == c*c) {
        return 1;
    } else if ((b*b + c*c) == a*a) {
        return 1;
    } else if ((c*c + a*a) == b*b) {
        return 1;
    } else {
        return 0;
    }
}