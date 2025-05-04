#include<bits/stdc++.h>;
using namespace std;
int main(){
int a[5];
for( int s = 0; s < 5; s++){
 cin >> a[s];
}
sort( a, a + 5, greater<int>());
for(int i = 0; i < 5; i++){
if( i < 4 ){
cout << a[i] << " ";
}else{
cout << a[i] << endl;
}
}
return 0;
}