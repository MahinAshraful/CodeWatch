#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(int argc, char const* argv[])
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);

    vector<int> nl;
    int mx = 0;
    do{
        int n;
        cin >> n;
        if (!cin.eof()){
            nl.push_back(n);
            mx = max(mx, n);
        }else{
            break;
        }
    }while(1);

    double r = sqrt(mx);

    list<int> sl;
    vector<int> primes;

    for (int i = 2; i <= mx; i++) {
        sl.push_back(i);
    }

    while (sl.front() <= r) {
        int p = sl.front();
        primes.push_back(p);
        sl.pop_front();

        auto i = sl.begin();
        while(i != sl.end()){
            if(*i % p == 0){
                i = sl.erase(i);
            }
            else {
                i++;
            }
        }
    }

    for (auto&& i : sl) {
        primes.push_back(i);
    }

    for (auto&& n : nl) {
        auto p = upper_bound(primes.begin(), primes.end(), n);
        cout << p - primes.begin() << endl;
    }

    return 0;
}