#include <iostream>
#include <cstdio>
#define N 2
using namespace std;

class Calc{
    public:
    double A[N][N+1];
    int i, j, k;
    double tmp;
    void calcSi();
    void printSi();
};

void Calc::calcSi(){
    for(i=0;i<N-1;i++){
        for(j=i+1;j<N;j++){
            tmp = A[j][i] / A[i][i];
            for(k=i+1; k<=N; k++)
                A[j][k] -= A[i][k] * tmp;
        }
    }

    for(i=N-1; i>=0; i--){
        tmp = A[i][N];
        for(j=i+1;j<N;j++)
            tmp -= A[i][j] * A[j][N];
        A[i][N] = tmp / A[i][i];
    }
}

void Calc::printSi(){
    for(i=0;i<N;i++){
        printf("%.3f",A[i][N]);
        if(i != N-1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main(void){
    Calc c;
    while(cin >> c.A[0][0] >> c.A[0][1] >> c.A[0][2] >> c.A[1][0] >> c.A[1][1] >> c.A[1][2]){
        c.calcSi();
        c.printSi();
    }
    return 0;
}