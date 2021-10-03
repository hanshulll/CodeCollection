'''
My Hackerearth profile: https://www.hackerearth.com/@prakhara72  :)
'''

import sys
input=sys.stdin.readline
from math import *
 
def inp(): return map(int,input().split())
 
for _ in range(int(input())):
    n,k=inp()
    if k<n-2:
        m=ceil(n/3)
        p=ceil((n-k)/2)
        q=floor((n+k)/2)
        ans=0
        if m<p:
            res=p-m
            fs=3*m-n+1
            ls=ceil((3*(p-1)-n+1)/2)
            cur=(ls*(ls+1))//2
            if fs==1:
                nc=(ls-3)//3+1
                cur-=(nc*(6+(nc-1)*3))//2
            elif fs==2:
                nc=(ls-2)//3+1
                cur-=(nc*(4+(nc-1)*3))//2
            else:
                nc=(ls-1)//3+1
                cur-=(nc*(2+(nc-1)*3))//2
            ans+=cur
        if q+2<n:
            res=n-q-2
            rem=ceil(res/2)
            cur=rem*(rem+1)
            if res&1:
                cur-=rem
            ans+=cur
        sys.stdout.write(str(ans)+"\n")
    else:
        print(0)
