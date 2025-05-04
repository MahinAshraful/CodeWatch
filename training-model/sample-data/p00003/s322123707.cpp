#include<stdio.h>
#include<string.h>
#include<math.h>

main()
{
    int t;
    double a,b,c,res;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf%lf%lf",&a,&b,&c);

        if((a*a+b*b)==c*c)
        {
            printf("YES\n");
        }
        else if((b*b+c*c)==a*a)
        {
            printf("YES\n");
        }
        else if((c*c+a*a)==b*b)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}