#include<iostream>
#define N_MAX 999999


int prime[( N_MAX + 1 ) / 2 ];
int memo[ N_MAX + 1 ];

int mkprime( void );

int main( void )
{
	int n;

	prime[0] = 2;
	memo[1] = 0;
	memo[2] = 1;

	mkprime();

	while( std::cin >> n ){
		std::cout << memo[n] << std::endl;
	}
	
	return 0;
}

int mkprime( void ){
	int i, j, endindex = 1;

	for( i = 3; i < N_MAX + 1; i++ ){
		for( j = 0; prime[j] * prime[j] <= i; j++ ){
		if( i % prime[j] == 0 ){
				goto tag;
			}
		}

		prime[ endindex ] = i;
		endindex++;

tag:
		memo[i] = endindex;
	}
}