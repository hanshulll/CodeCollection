#include<stdio.h> 

//iterative approach of getting fibonachchi sequence   

int main()    
{    
 int v1=0,v2=1,v3,i,num;  
   
 printf("Input the number of elements in the sequence :");    
 scanf("%d",&num);   
 
 if(num<2)
 {
 	printf("\n%d",v1);
 }
 else
 {
 
	printf("\n%d %d",v1,v2);//printing 0 and 1 
	
	for(i=2;i<num;++i)//loop starts from 2 because 0 and 1 are already printed    
	{    
	v3=v1+v2;    
	printf(" %d",v3);   
	v1=v2;    
	v2=v3;    
	}
  }
    return 0;  
 }    
