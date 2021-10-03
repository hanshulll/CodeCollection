// Program to find factorial if a number.
#include<stdio.h>
int main(){
	int fact=1,num,i;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
		fact=fact*i;
	printf("Fact(%d) = %d",num,fact);
	return 0;
}
