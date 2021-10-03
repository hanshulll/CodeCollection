#include <stdio.h>
int insert(int a[],int n);
int delete(int a[],int n);
int reverse(int a[],int n);
int search(int a[],int n);
int main()
{   
    int n;
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];	
	int i, ch, pos;	
    printf("Enter the %d numbers \n",n);
	for (i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int c=1;
    while(c!=0){
    printf("    Enter choice    \n");
    printf("Press 1 to Insert \n");
    printf("Press 2 to Delete \n");
    printf("Press 3 to Reverse \n");
    printf("Press 4 to Search \n");
    printf("Press 5 to Exit \n");
    scanf("%d",&ch);    
    switch (ch)
    {
    case 1:
        n++;
        insert(a,n);
        break;
    case 2:
        n--;
        delete(a,n);
        break;
    case 3:
        reverse(a,n);
        break; 
    case 4:
        search(a,n);
        break;     //vvvcvcc      
    default:
        printf("Gone too soon ");
        c=0;
        break;
    }}
    
}
int insert(int a[],int n){
    int pos,x;
    printf("Enter the value and position to be inserted : ");
    scanf("%d %d",&x,&pos);
    /*n++;*/

	for (int i = n-1; i >= pos; i--){
		a[i] = a[i - 1];}
	a[pos - 1] = x;

	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");	

}
int delete(int a[], int n){
    int pos;
    printf("Enter the position to be deleted : ");
    scanf("%d",&pos);
    	/*n--;*/

	for (int i = pos-1; i <= n; i++){
		a[i] = a[i + 1];}

	
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int reverse(int a[],int n){
    int b[n];	
    printf("The original array : ");
    for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
    int d = n-1;
    printf("The reverse array : ");
    for (int i = d; i >= 0; i--){
        b[d-i]=a[i];
    }
    for (int i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
}
int search(int a[],int n){
    int b;
    printf("Enter the no to be searched : ");
    scanf("%d",&b);
    int f,j;
    for (j = 0; j < n; j++){
        if(a[j]==b){
        f = 1;
        break;}
    }
    if(f==1)
    printf("%d is present at pos %d \n",b,j+1);
    else
    printf("%d is not present \n",b);
}
