/*
Author: Siddhant Pandya
Program: Working Lift
Difficulty: Easy
*/
#include<stdio.h>
void main()
{
	char p[9];
	strcpy(p,"L        ");
	int loop=0;
	int u,lf=0,b,t;
while(loop==0) {
	
	
	printf("Lift is on %d floor...\n",lf);
	printf("Where are you: ");
	scanf("%d",&u);
	printf("Please wait lift is processing...\n");
	sleep(1);
	while(u!=lf)
	{
	

	if(u<lf) {p[lf]=' '; lf--;	p[lf]='L'; }	
	else {p[lf]=' '; lf++; p[lf]='L';	}

	for(b=8;b>=0;b--)
	{
		printf("%d %c\n",b,p[b]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");
		for(t=1;t<1000000000;t++) {	}
	}
	
	
	printf("Please be in the lift...\n");
	printf("Where do you want to go: ");
	scanf("%d",&u);
	
	while(u!=lf)
	{

	if(u<lf) {p[lf]=' '; lf--;	p[lf]='L'; }	
	else {p[lf]=' '; lf++; p[lf]='L';	}

	for(b=8;b>=0;b--)
	{
		printf("%d %c\n",b,p[b]);
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n");
		for(t=1;t<1000000000;t++) {	}
	}
		
	printf("You have reached your destination...\n");
}}
