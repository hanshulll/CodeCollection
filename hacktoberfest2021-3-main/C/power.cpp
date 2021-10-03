#include <stdio.h>


  
float power(int a,int n){
	float R;
    if(n==0)
    return 1;
    if (n==1)
   return a;
    
	
  R=power(a,n/2);
  printf("%f\n",R);
    if (n%2==0)
    return R*R;
	
    else
  
            return a*R*R;
       
}

int main()
{
    float a;
    printf("enter the base");
    scanf("%f",&a);
    int n;
    printf("enter the power of a");
    scanf("%d",&n);
   
    printf("%f", power(a, n));
    return 0;
}
  


