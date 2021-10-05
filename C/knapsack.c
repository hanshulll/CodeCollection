#include<stdio.h>
void k_s(int n, float w_t[],float p_t[],int c_t)
{
    float x[20],t_p=0;
    int i,j,u;
    u=c_t;
    for (i=0;i<n;i++){
        x[i]=0.0;
    }
    for (i=0;i<n;i=i+1) {
        if(w_t[i]>u)
            break;
        else{
            x[i]=1.0;
            t_p=t_p+p_t[i];
            u=u-w_t[i];
        }
    }
    if(i<n) {
        x[i]=u/w_t[i];
    }
    t_p=t_p+(x[i]*p_t[i]);
    printf("%f",t_p);
}
int main(){
    int n,t_y;
    scanf("%d",&n);
    float w_t[n],p_t[n],r_t[n];
    int c_t;
    for(int i=0;i<n;i=i+1) {
        scanf("%f",&w_t[i]);
    }
    for(int i=0;i<n;i=i+1)
    {
        scanf("%f",&p_t[i]);
    }
    scanf("%d",&c_t);
    for(int i=0;i<n;i=i+1){
        r_t[i]=p_t[i]/w_t[i];
    }
    for(int i=0;i<n;i=i+1){
        for(int j=i+1;j<n;j=j+1)
        {
            if(r_t[i]<r_t[j]){
                t_y=r_t[j];
                r_t[j]=r_t[i];
                r_t[i]=t_y;
                t_y=w_t[j];
                w_t[j]=w_t[i];
                w_t[i]=t_y;
                t_y=p_t[j];
                p_t[j]=p_t[i];
                p_t[i]=t_y;
            }
        }
    }
    k_s(n,w_t,p_t,c_t);
    return 0;
}
