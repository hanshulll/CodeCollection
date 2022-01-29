#include<stdio.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n,m,i,j,fl=0;
    scanf("%d",&n);
    int arn[n];
    for(i=0;i<n;i++) scanf("%d",&arn[i]);
    scanf("%d",&m);
    int arm[m];
    for(i=0;i<m;i++) scanf("%d",&arm[i]);
    long long int ans=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            ans*=gcd(arn[i],arm[j]);
            if(ans>1000000000) fl=1;
            ans=ans%1000000000;
        }
    }
    printf("Calc done");
    if(fl)
    {
        if(ans<10) printf("00000000");
        else if(ans<100) printf("0000000");
        else if(ans<1000) printf("000000");
        else if(ans<10000) printf("00000");
        else if(ans<100000) printf("0000");
        else if(ans<1000000) printf("000");
        else if(ans<10000000) printf("00");
        else if(ans<100000000) printf("0");
    }
    printf("%lld\n",ans);
    return 0;
}
