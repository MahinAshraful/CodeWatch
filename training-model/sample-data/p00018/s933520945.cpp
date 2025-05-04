#include<iostream>
using namespace std;

int main(){

int a,b,c,d,e;
cin >> a >> b >> c >> d >> e;
int r = 0;
if(a < b){
r = a;
a = b;
b = r;
}
if(a < c){
r = a;
a = c;
c = r;
}
if(a < d){
r = a;
a = d;
d = r;
}
if(a < e){
r = a;
a = e;
e = r;
}

if(b < c){
r = b;
b = c;
c = r;
}
if(b < d){
r = b;
b = d;
d = r;
}
if(b < e){
r = b;
b = e;
e = r;
}
if(c < d){
r = c;
c = d;
d = r;
}
if(c < e){
r = c;
c = e;
e = r;
}
if(d < e){
r = d;
d = e;
e = r;
} 
cout << a << " "<< b <<" "<< c << " " << d << " " << e << endl;
    return 0;
}