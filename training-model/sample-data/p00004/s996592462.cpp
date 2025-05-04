#include <iostream>
using namespace std;

int rnd(double t){
	if(t>=0.0){
		return (int)(t+0.5);
	}else{
		return (int)(t-0.5);
	}
}
void prnt(double t){
	if(t<0.0){
		cout<<"-";
		t*=-1;
	}
	cout<<(int)t<<"."<<(int)(t*10)-(int)t*10<<(int)(t*100)-(int)(t*10)*10<<(int)(t*1000)-(int)(t*100)*10;
}
int main(){
	double a,b,c,d,e,f,x,y;
	while(cin>>a>>b>>c>>d>>e>>f){
		x=(c*e-b*f)/(a*e-b*d);
		y=(a*f-c*d)/(a*e-b*d);
		x=rnd(x*1000.0)/1000.0;
		y=rnd(y*1000.0)/1000.0;
		prnt(x);
		cout<<" ";
		prnt(y);
		cout<<endl;
	}
	return 0;
}