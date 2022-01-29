def subarraysum(arr,n):
    sum1=0
    current=0
    for i in range(n):
        current=0
        for j in range(i,n):
            current+=arr[j]
            #print(current)      
            sum1+=current
    return sum1

arr=[1,2,0,7,2]
n=len(arr)
print(subarraysum(arr,n))

#github username: https://github.com/kadambinipanda 
