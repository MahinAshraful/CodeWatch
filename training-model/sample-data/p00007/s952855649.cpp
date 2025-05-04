#include<iostream>

int solve( int, int );

int main( void )
{
	int n;

	std::cin >> n;

	std::cout << solve( n, 100000 ) << std::endl;

	return 0;
}

int solve( int n, int debt ){
	int tmp = (int)((( debt * 1.05 ) + 999 ) / 1000 );

	if( n == 1 ){
		return tmp * 1000;
	}

	return solve( n - 1, tmp * 1000 );
}