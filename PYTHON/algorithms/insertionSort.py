# Python program for insertion sort
  
#function for the insertion sort
def insertionsort(A):
    #getting the length of the array
    n=len(A) 
    #traverse through 1 to length of the array
    for j in range(1,n):
        key=A[j]
        i=j-1
        #compare key with each element on the left of it
        #until an element smaller than it is found
        while(i>=0 and A[i]>key):
            A[i+1]=A[i]
            i=i-1
        #place key after the element that is smaller than it.
        A[i+1]=key
        
# Main program
print("array before insertion sort")
A = [22, 12, 43, 2, 60]
print(A)
insertionsort(A)

print("array after insertion sort")
insertionsort(A)
print(A)
