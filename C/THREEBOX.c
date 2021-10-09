// Author : Shreya Gupta
//Question Link : https://www.codechef.com/OCT21C/problems/THREEBOX

#include <stdio.h>

int main(void) {
int T,A,B,C,D,x,y,z,i;
x=1;
y=2;
z=3;
scanf("%d",&T);
//This will take the input
for(i=1;i<=T;i++){
    scanf("%d%d%d%d",&A,&B,&C,&D);
    //This will take the input
    
    if(A+B+C>D){
        if(B+C>D){
        	if(C+A>D){ 
        		if(B+A>D){
        			 printf("%d\n",z);
        		}
        		
        		else{ printf("%d\n",y);}
        		
        	}
        	
        	else{ printf("%d\n",y);}
        }
        
        else { printf("%d\n",y);}
    }
  
    else{
        printf("%d\n",x);
    }}

return 0; }
