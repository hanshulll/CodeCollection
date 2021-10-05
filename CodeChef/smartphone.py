n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
revenue=0
for i in l:
    s=0
    x=i
    for j in l:
        if(j>x):
            s=s+1
    revenue=x*s