#include "bits/stdc++.h"
using namespace std;
int main(){
    double a, b, c, d, e, f;
    while(cin >> a >> b >> c >> d >> e >> f){
        double M[2][3] = { 
            {a, b, c},
            {d, e, f}
        };
        double d = 0, m = 0;
        for(int i=0; i<2; ++i)
        {  
            d = M[i][i];
            for(int j=0; j<3; ++j){
                M[i][j] = M[i][j] / d;
            }
            for(int k = i+1; k<2; k++){
                m = M[k][i];
                for(int n = i; n<3; ++n){
                    M[k][n] = M[k][n] - m * M[i][n];
                }
            }
        }
        
        for(int i = 1; i>0; --i){
            for(int j= i-1; j>=0; --j){
                d = M[j][i];
                for(int n=i; n<3; ++n){
                    M[j][n] = M[j][n] - d * M[i][n];
                }
            }
        }
        for(int i=0; i<2; i++){
            if(i == 1) {
                printf("%.3lf\n", M[i][2]); break;
            }
            printf("%.3lf ", M[i][2]);
            
        }
    }
    return 0;
}