#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<int> v;
    int n;
    for (int i = 0; i < 5; i++){
	cin >> n;
	v.push_back(n);
    }
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0; i < 5; i++)
	printf("%d%c", v[i], (i == 4)? '\n':' ');

}