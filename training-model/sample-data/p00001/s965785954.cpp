#include <cstdio>
#include <set>
#include <iterator>

int main() {
    std::multiset<int> ms;
    int d;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &d);
        ms.insert(d);
    }
    for (auto i = ms.rbegin(); i != std::next(ms.rbegin(), 3); ++i) {
        printf("%d\n", *i);
    }
}