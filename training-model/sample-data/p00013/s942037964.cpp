#include<stdio.h>

int	i	=	0,	result;
int	train[100];
int outtrain[100];

void	push(int	k){
	train[i]	=	k;
	i++;
}

void	pop(int train[]){
	int	a,	check	=	0;
	for(a	=	i	-	1;	a	>=	0;	a--){
		if(train[a]	!=	0){
			result	=	train[a];
			train[a]	=	0;
			check	+=	1;
		}
		if(check	!=	0)break;
	}
}


int	main(){
	int	k,	cnt	=	0;
	outtrain[100]	=	0;
	while(scanf("%d",	&k) != EOF){
		push(k);
		if(k	==	0){
			pop(train);
			outtrain[cnt]	=	result;
			cnt++;
			i	-=	2;
		}
	}
	for(k	=	0;	k	<=	cnt;	k++){
		if(outtrain[k]	!=	0)printf("%d\n",	outtrain[k]);
	}
	return 0;
}


	