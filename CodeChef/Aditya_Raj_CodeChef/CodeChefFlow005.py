#CodeChefFlow005
l=[100,50,10,5,2,1]
n=int(input())
for i in range(n):
    m=int(input())
    count=0
    j=0
    for num in l:
        j=int(m/num)
        count+=j
        m=int(m%num)
        if m==0:
            break
    print(count)