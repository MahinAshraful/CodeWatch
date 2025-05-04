

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

const int MAX_HORIZONTAL = 30;
const int MAX_VERTICAL = 30;

int main(){

	int VerticalLines;
	int HorizontalLines;
	int HorizonA[MAX_HORIZONTAL];
	int HorizonB[MAX_HORIZONTAL];
	int Results[MAX_VERTICAL];



	cin >> VerticalLines;
	cin >> HorizontalLines;
	for (int i = 0; i < HorizontalLines; ++i){ char c[32];  scanf("%d,%d", &HorizonA[i], &HorizonB[i]); }

	for (int i = 0; i < VerticalLines; ++i){ Results[i] = i + 1; }

	

	for (int i = 0; i < HorizontalLines; ++i){
		int Swap = Results[HorizonA[i] - 1];
		Results[HorizonA[i]-1] = Results[HorizonB[i] - 1];
		Results[HorizonB[i] - 1] = Swap;
	}

	
	for (int i = 0; i < VerticalLines; ++i){
		cout << Results[i] << endl;
	}





	return 0;
}