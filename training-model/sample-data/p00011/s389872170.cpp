#include <iostream>
#include <vector>
#include <string>
using namespace std;
void swap(int &a, int &b){
	int c=a;
	a=b;
	b=c;
}
vector<int> v;

int main(){
	int w, n;
	cin >> w >> n;
	int a[n], b[n];
	string s;
	for(int i=0; i<n; i++){
		cin >> s;
		a[i] = stoi(s);
		while(1){
			if(s[0]!=',') s.erase(s.begin(), s.begin()+1);
			else{
				s.erase(s.begin(), s.begin()+1);
				break;
			}
		}
		b[i] = stoi(s);
	}

	v.resize(w);
	for(int i=0; i<v.size(); i++) v[i]=i+1;
	for(int i=0; i<n; i++){
		swap(v[a[i]-1], v[b[i]-1]);
	}

	for(int i=0; i<n; i++) cout << v[i] << endl;

	return 0;
}