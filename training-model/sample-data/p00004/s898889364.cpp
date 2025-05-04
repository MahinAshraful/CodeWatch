#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * Simultaneous Equation
 * ax + by = c
 * dx + ey = f
 */
int main()
{
    vector <double> xlist;
    vector <double> ylist;
    double a, b, c, d, e, f;
    double x = 0,y = 0;
    while(cin >> a >> b >> c >> d >> e >> f)
    {
        double dA = a*e - b*d;
        if(dA == 0)
        {
            //Not Calc
            return -1;
        }
        x = 1/dA*(e*c-b*f);
        y = 1/dA*(-d*c+a*f);
        xlist.push_back(x);
        ylist.push_back(y);

    }
    for(int i; i < (int)xlist.size(); i++)
    {
        x = xlist[i];
        y = ylist[i];
        if(x == 0)
        {
            x = fabs(x);
        }
        if(y == 0)
        {
            y = fabs(y);
        }
        printf("%.3f %.3f\n",x,y);
    }

    return 0;
}