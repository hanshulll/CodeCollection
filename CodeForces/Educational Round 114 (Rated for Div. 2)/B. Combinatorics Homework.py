t = int(input())
while t>0:
    val = [int(a) for a in input().split()]
    a,b,c,m = val
    if (a-1)>b+c+m or (b-1)>a+c+m or (c-1)>a+b+m:
        print("NO")
    elif m<=(a+b+c-3):
        print("YES")
    else:
        print("NO")
    t-=1