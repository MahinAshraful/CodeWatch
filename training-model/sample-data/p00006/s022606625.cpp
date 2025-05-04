#include <iostream>
#include <string>
using namespace std;

int main(){
    int number;
    char str[21];
    cin >> str;
    for(int i=0;i<21;i++){
        if(str[i]=='\0')
            number=i;
    }
    char reverse[number+1];
    for(int i=0;i<number;i++){
        reverse[i]=str[number-1-i];
    }
    for(int i=0;i<number;i++){
        cout << reverse[i];
    }
    cout << endl;
}