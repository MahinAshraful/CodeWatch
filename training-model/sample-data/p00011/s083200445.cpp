#include <stdio.h>
main() {
  int d[31];
  int buf,i,w,n,a,b;
  scanf("%d%d",&w,&n);
  for(i=1;i<=w;i++) {
    d[i]=i;
  }
  for(i=0;i<n;i++) {
    scanf("%d,%d",&a,&b);
    buf=d[a];d[a]=d[b];d[b]=buf;
  }
  for(i=1;i<=w;i++) printf("%d\n",d[i]);
}