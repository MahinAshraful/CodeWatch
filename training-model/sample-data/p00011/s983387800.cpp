#include <stdio.h>

int main()
{
int p[31]={0};
int w,n,a,b;
char e;
int tmp;
tmp=0;
scanf("%d",&w);scanf("%d",&n);
for(int i=0;i<w;i++)
p[i]=i+1;
for(int i=0;i<n;i++)
{
scanf("%d,%d",&a,&b);
tmp=p[a-1];p[a-1]=p[b-1];p[b-1]=tmp;

}

for(int i=0;i<w;i++)
printf("%d\n",p[i]);

return 0;
}