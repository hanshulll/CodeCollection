// Best Case:- O(1), worst case:- O(n), average case:- O((n+1)/2)
// Use Cases:- Linear search is generally preferred for smaller and random ordered datasets.
//             and is less efficient in the case of larger datasets

#include<stdio.h>

int main(){
    int len,i,found=0,data,pos;
    printf("Enter the number of items in the array:");
    scanf("%d", &len);
    int arr[len];
    for(i=0;i<len;i++){
        printf("Enter the element %d:",(i+1));
        scanf("%d", &arr[i]);
    }
    printf("Enter the number you want to search:");
    scanf("%d",&data);
    for(i=0;i<len;i++){
        if(arr[i]==data){
            found=1;
            pos=i;
            break;
        }
    }
    (!found) ? printf("Element Not Found") : printf("Element Present at array index %d",pos);
    return 0;
}