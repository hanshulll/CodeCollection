#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n][n],b[n][n],c[n][n];
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            c[i][j]=0;
        }
    }
    str_n(a,b,c,n,n);
    for(int i=0;i<n;i=i+1)
    {
        for(int j=0;j<n;j=j+1)
        {
            printf("\n%d",c[i][j]);
        }
    }
    
}
void str_n(int *a,int *b,int *c,int m,int n)
{
    if(m==2)
    {
        int P=(*a+*(a+n+1))*(*b+*(b+n+1));
        int Q=(*(a+n)+*(a+n+1))*(*b);
        int R=(*a)*(*(b+1)-*(b+n+1));
        int S=(*(a+n+1))*(*(b+n)-*b);
        int T=(*a+*(a+1))*(*(b+n+1));
        int U=(*(a+n)-*a)*(*b+*(b+1));
        int V=(*(a+1)-*(a+n+1))*(*(b+n)+*(b+n+1));
        *c=*c+P+S-T+V;
        *(c+1)=*(c+1)+R+T;
        *(c+n)=*(c+n)+Q+S;
        *(c+n+1)=*(c+n+1)+P+R-Q+U;
    }
    else
    {
        m=m/2;
        str_n(a,b,c,m,n);
        str_n(a,b+m,c+m,m,n);
        str_n(a+m,b+m*n,c,m,n);
        str_n(a+m,b+m*(n+1),c+m,m,n);
        str_n(a+m*n,b,c+m*n,m,n);
        str_n(a+m*n,b+m,c+m*(n+1),m,n);
        str_n(a+m*(n+1),b+m*n,c+m*n,m,n);
        str_n(a+m*(n+1),b+m*(n+1),c+m*(n+1),m,n);
    }
}
