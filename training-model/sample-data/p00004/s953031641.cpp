#include<iostream>
#include<cmath>
using namespace std;

int fff(double x){
	if(x==(int)x){return 3;}
	else if(x*10==(int)(x*10)){return 2;}
	else if(x*100==(int)(x*100)){return 1;}
	else if(x*1000==(int)(x*1000)){return 0;}
}

int main(){
	double k[60000]={0};
	int i=0;
	while(cin>>k[i++]);
	int n=i-1;
	for(int j=0;j<n;j+=6){
		double x=0,y=0,a=k[j],b=k[j+1],c=k[j+2],d=k[j+3],e=k[j+4],f=k[j+5];
		x=(c*e-b*f)/(-b*d+a*e);
		y=(c*d-a*f)/(b*d-a*e);
		if(x==0)x=abs(x);
		if(y==0)y=abs(y);
		x*=1000,x=round(x),x/=1000;
		y*=1000,y=round(y),y/=1000;
		cout<<x;int fx=fff(x);
		if(fx==3){cout<<".000 ";}
		if(fx==2){cout<<"00 ";}
		if(fx==1){cout<<"0 ";}
		if(fx==0){cout<<" ";}
		cout<<y;int fy=fff(y);
		if(fy==3){cout<<".000";}
		if(fy==2){cout<<"00";}
		if(fy==1){cout<<"0";}
		cout<<endl;
		
	}
	return 0;
}