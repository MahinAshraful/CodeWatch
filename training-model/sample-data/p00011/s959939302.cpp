#include <iostream>
#include <sstream>
using namespace std;


void swap(int,int);
int ladder[50];
string change;

int main(){
	int v,h,a,b;
	cin >> v >> h;
	for(int i=1;i<=v;i++){
		ladder[i]= i;
	}
	for(int i=1;i<=h;i++){
		cin >> change;
		//cout << change[2];
		change.replace(change.find(","),1," ");
		//tmp.replace(tmp.find(","),1," ");
		istringstream ss(change);
		ss >> a >> b;

		//temp = ladder[b];
		//ladder[b] = ladder[a];
		//ladder[a] = temp;
//		cout << ladder[a] << ladder[b] << endl;
	//	cout << endl << endl;
		swap(a,b);
		/*for(int i=1;i<=v;i++){
			cout << ladder[i] << endl;
		}
		cout << endl;*/
		//	cout << ladder[change[0]] << "-"<<ladder[change[2]] << endl;
	}
//	cout <<endl;

	for(int i=1;i<=v;i++){
	cout << ladder[i] << endl;
	}
}

void swap(int a,int b){
	int temp;
	temp = ladder[b];
	ladder[b] = ladder[a];
	ladder[a] = temp;
	/*cout << ladder[a] << ladder[b] << endl;
	cout << endl << endl;*/
}