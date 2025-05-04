#include <stdio.h>
main(){
  int cur,a[5],i,max,tmp;
  while( scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]) !=EOF){
  for(cur=0;cur<5;cur++){
    max=cur;
    for(i=cur;i<5;i++){
      if(a[i]>a[max]){
	max=i;
      }
    }
    tmp=a[cur];
    a[cur]=a[max];
    a[max]=tmp;
  }
    printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],a[4]);
  }
return 0; 
}