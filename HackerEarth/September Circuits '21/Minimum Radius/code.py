'''
Problem: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/minimum-radius-2-29df5cb3/
Implemented binary search in the solution
'''

import bisect
import math
from sys import stdin,stdout
input=stdin.readline
 
def inp(): return map(int,input().split())
 
for _ in range(int(input())):
    n,p=inp()
    l=[]
    x=list(inp())
    y=list(inp())
    v=list(inp())
    for i in range(n):
        l.append((math.sqrt(x[i]**2+y[i]**2),v[i]))
    l.sort()
    c=l[0][1]
    res=[c]
    for i in range(1,n):
        c+=l[i][1]
        res.append(c)
    rem=bisect.bisect_left(res,p)
    if rem>n-1:
        print(-1)
    else:
        print(math.ceil(l[rem][0]))
