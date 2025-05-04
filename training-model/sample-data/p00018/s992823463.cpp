#include <stdio.h>
void qsort(int a[],int left,int right)
{
	if(left < right)
	{
		int pvot,tmp,i,j;
		i = left;
		j = right;
		pvot = (a[i] + a[j])/2;
		while(1)
		{
			while(a[i] < pvot)i++;
			while(a[j] > pvot)j--;
			if(i >= j)
			{
				break;
			}
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
			i++;
			j--;
		}
		qsort(a,left,i -1);
		qsort(a,j + 1,right);
	}
	return;
}
int main(void)
{
	int i,n;
	int array[5];
	for(i = 0;i < 5;i++)
	{
		scanf("%d",&array[i]);
	}
	qsort(array,0,4);
	for(i = 0;i < 4;i++)
	{
		printf("%d ",array[4-i]);
	}
	printf("%d\n",array[0]);
	return 0;
}