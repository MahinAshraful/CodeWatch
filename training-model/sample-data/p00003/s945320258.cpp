#include <iostream>
using namespace std;

int main(){
    
	int i, a, b, c;
    int ab=0, bc=0, ca=0;
    
	cin >> i;
    
	while(i-- > 0){
        
		cin>> a>> b>> c;
        
        ab = a*a+b*b;
        bc = b*b+c*c;
        ca = c*c+a*a;
		
		if(ab == c*c || bc==a*a || ca==b*b) cout << "YES" << endl;
		else cout << "NO" << endl;
        
	}
    
    
	return 0;
}