#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
void lots(int len,int a,int b,int array[]){
    int buffer[len];
    for(int i = 0;i < len; i++){
        if(i == a-1){
            buffer[i] = array[b-1];
        }
        else if(i == b-1){
            buffer[i] = array[a-1];
        }
        else{
            buffer[i] = array[i];
        }
    }
    for(int i = 0; i < len; i++){
        array[i] = buffer[i];
    }

}

int main(){
    int len,duration,a,b;
    cin >> len;
    cin >> duration;
    int array[len];
    for(int i = 0; i < len; i++){
        array[i] = i+1;
    }
    for(int i = 0; i < duration; i++){
        scanf("%d,%d",&a,&b);
        lots(len,a,b,array);
    }
    for(int i = 0; i < len; i++){
        cout << array[i] << endl;
    }
}