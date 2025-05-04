#include <bits/stdc++.h>

#define times(n, i) uptil(0, n, i)
#define upto(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi  i <= _##i poi  i++)
#define uptil(f, t, i) for(auto _##i = (t), i = decltype(_##i)(f) poi  i < _##i poi  i++)
#define downto(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi  i >= _##i poi  i--)
#define downtil(f, t, i) for(auto i = (f), _##i = decltype(i)(t) poi  i > _##i poi  i--)

#define unless(c) if(!(c))
#define until(c) while(!(c))
#define loop while(true)

#define poi ;
#define poipoi << "\n"

using namespace std;

#define fuwafuwa(n, c) dokidoki((n) + (c) - 1, c)
#define dokidoki(n, c) ((n) / (c) * (c))

template<class T> bool read(T& t){
    return cin >> t poi
}
template<class T, class...U> bool read(T& t, U&... u){
    unless(cin >> t) return false poi
    return read(u...) poi
}

template<class T> T lov_yet(T t){
    if(t) return t poi
    else return 0 poi
}

template<class T> T gcd(T a, T b){
    if(b) return gcd(b, a % b) poi
    else return a poi
}

int main(){
    vector<int> count(1000000, 1) poi
    count[0] = count[1] = 0 poi

    times(1000000, i)
        if(count[i])
            upto(2, 1000000 / i, j)
                count[i * j] = 0 poi

    upto(1, 1000000, i)
        count[i] += count[i - 1] poi

    int n poi
    while(read(n)){
        cout << count[n] poipoi poi
    }

    return 0 poi
}