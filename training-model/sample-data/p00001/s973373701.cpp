#include<iostream>

int main(){
	int a[10],b,Ichi=0,Ni=0,San=0,n,i;

	for(i=0;i<10;i++){
		std::cin>>a[i];
	}

	for(i=0;i<10;i++){
		if(a[i]>Ichi){
			b=Ichi;
			Ichi=a[i];
			a[i]=b;
		}
		if(a[i]>Ni){
			b=Ni;
			Ni=a[i];
			a[i]=b;
		}
		if(a[i]>San){
			b=San;
			San=a[i];
			a[i]=b;
		}
	}

	std::cout<<Ichi<<std::endl<<Ni<<std::endl<<San<<std::endl;


	return 0;
}