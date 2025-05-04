#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<sstream>
using namespace std;

	int stoi(string a){
		int b;
		stringstream ss;
		ss<<a;
		ss>>b;
		return b;
	}
	string itos(int a){
		stringstream ss;
		ss >>a;
		string b;
		b=ss.str();
		return b;
	}

int main(){
	int w,n,ans[40]={0};
	cin>>w>>n;
	for(int i=0;i<40;i++)ans[i]=i+1;
	for(int i=0;i<n;i++){
		string a,maes,usis;int kan,mae,usiro;
		cin>>a;
		kan=a.find(',');
		maes=a.substr(0,kan);
		usis=a.substr(kan+1,a.size()-kan);
		mae=stoi(maes);
		usiro=stoi(usis);
		swap(ans[mae-1],ans[usiro-1]);
	}
	for(int i=0;i<w;i++)cout<<ans[i]<<endl;
    return 0;
}