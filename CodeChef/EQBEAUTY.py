import math;from heapq import heappush,heappop,heapify;import random;import string;from collections import deque;from bisect import bisect,bisect_left,bisect_right,insort;import sys;input=sys.stdin.readline;S=lambda:input().rstrip();I=lambda:int(S());M=lambda:map(int,S().split());L=lambda:list(M());H=1000000000+7

for _ in range(I()):

 n=I();l=L()

 l.sort();m=math.inf

 for i in range(2,n-1):

  d1=l[i]-l[0]

  t=l[-1]-d1

  p=bisect_left(l,t,1,i-1)

  if p==1 : m=min(m,abs(l[-1]-l[p]-d1));continue 

  if p==i: m=min(m,abs(l[-1]-l[p-1]-d1));continue

  m=min(m,abs(l[-1]-l[p]-d1),abs(l[-1]-l[p-1]-d1))

 for i in range(1,n-2):

  m=min(m,abs(l[i]-l[0]-l[-1]+l[i+1]))

 x=[(l[0],1)]

 for i in range(1,n):

  x.append((x[i-1][0]+l[i],x[i-1][1]+1))

 s=sum(l)

 for i in range(n):

  if n%2==0:

   p=n//2

   if i>=n//2: 

    p-=1

    k=l[p]*x[p][1]-x[p][0]+(s-x[p][0]-l[i])-(n-1-x[p][1])*l[p]

   else:

    k=l[p]*(x[p][1]-1)-(x[p][0]-l[i])+(s-x[p][0])-(n-x[p][1])*l[p]

  else:

   if i<n//2:

    p1=n//2;p2=n//2 +1

    k1=l[p1]*(x[p1][1]-1)-(x[p1][0]-l[i])+(s-x[p1][0])-(n-x[p1][1])*l[p1]

    k2=l[p2]*(x[p2][1]-1)-(x[p2][0]-l[i])+(s-x[p2][0])-(n-x[p2][1])*l[p2]

    k=min(k1,k2)

   elif i==n//2:

    p1=n//2 -1;p2=n//2 +1

    k1=l[p2]*(x[p2][1]-1)-(x[p2][0]-l[i])+(s-x[p2][0])-(n-x[p2][1])*l[p2]

    k2=l[p1]*x[p1][1]-x[p1][0]+(s-x[p1][0]-l[i])-(n-1-x[p1][1])*l[p1]

    k=min(k1,k2)

   else:

    p1=n//2;p2=n//2 -1

    k1=l[p1]*x[p1][1]-x[p1][0]+(s-x[p1][0]-l[i])-(n-1-x[p1][1])*l[p1]

    k2=l[p2]*x[p2][1]-x[p2][0]+(s-x[p2][0]-l[i])-(n-1-x[p2][1])*l[p2]

    k=min(k1,k2)

  m=min(k,m)

 print(m)
