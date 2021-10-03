//Simple Interest//
#include<stdio.h>

int main()
{
    int p; // p= principal //
    float n, ri, si, t; // n= time, ri= rate of interest, si= simple interest, t= Total //

    printf("Principal\n");
    
    scanf("%d",&p); // Enter principal value //

    printf("No. of years\n");

    scanf("%f",&n);  // Enter no. of years //

    printf("Rate of Interest\n");

    scanf("%f",&ri); // Enter the rate of Interest //

    si = p*ri/100*n;

    printf("Simple Interest = %f\n",si); // Prints the simple interest //

    t = p + si; // Total = principal + simple interest //

    printf("Total Amount after Interest = %f",t);  //Prints total amount after interest //

    return 0;


}
