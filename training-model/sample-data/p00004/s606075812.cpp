#include<stdio.h>
#include<iostream>
#include<cmath>
#define EPS 0.0000001

using namespace std;

main(){
  int a, b, c, d, e, f;
  double x, y;
  while ( cin >> a >> b >> c >> d >> e >> f ){
    x = 1.0 * ( c*e - b*f ) / ( a*e - b*d ) + EPS;
    y = 1.0 * ( c*d - a*f ) / ( b*d - a*e ) + EPS;
    printf("%.3lf %.3lf\n", x, y);
  }
}