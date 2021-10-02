# Problem statement: Consider an array  of  integers. We perform  queries of the following type on :
# Sort all the elements in the subsegment .
# Given , can you find and print the value at index  (where ) after performing  queries?

import sys

##### Read Data
dat = [x.split() for x in sys.stdin.readlines()]
N = int(dat[0][0])
Q = int(dat[0][1])
k = int(dat[0][2])
a = list(map(int, dat[1]))
q = [list(map(int, x)) for x in dat[2:len(dat)]]

##### Process Queries
b = sorted(a)
lmin, rmax, pmax, qmin = (N-1), 0, 0, (N-1)    
pmin, qmax, flag = (N-1), 0, 1
count, span_q, ladder, revlad = [], 0, 0, 0
if Q >= 2:
    ladder = all(q[i+1][0] > q[i][0] for i in range(Q-1)) 
    revlad = all(q[i+1][1] < q[i][1] for i in range(Q-1))

if a != b and ladder < 1 and revlad < 1:
    for i in range(Q):
        l, r = q[i][0], q[i][1]       
        
        if (r-l) > (rmax-lmin):
            lmin, rmax = l, r	
        
        if l < pmin:
            pmin, pmax = l, r
        elif l == pmin and pmax < r:
            pmax = r
            
        if r > qmax:
            qmin, qmax = l, r
        elif r == qmax and qmin > l:
            qmin = l
    
    for i in range(Q):
        l, r = q[i][0], q[i][1]
        
        if l > lmin and r < rmax: continue     
        if l > pmin and r < pmax: continue             
        if l > qmin and r < qmax: continue        
        
        if i < (Q-1):
            if l >= q[i+1][0] and r <= q[i+1][1]:
                continue
            
        if i > 0:
            if l >= q[i-flag][0] and r <= q[i-flag][1]:
                flag += 1
                continue
            else:
                flag = 1

        count += [i]
        span_q += r-l+1

# Perform Queries 
if ladder > 0:
    l, r, Qu = q[0][0], q[0][1], int((k+5)/5)
    a[l:r+1] = sorted(a[l:r+1])
    for i in range(1, Q):
        l, r, r0, m, sig = q[i][0], q[i][1], q[i-1][1], 0, 0
        if l > r0 or (r-r0) > 0.1*(r0-l):
            a[l:r+1] = sorted(a[l:r+1])
            continue
        if k < l: break
        count = list(range(r0+1, r+1))
        for j in range(len(count)):
            p, new_A = count[j], a[count[j]]
            l, r0 = q[i][0], q[i-1][1]
            if a[l] >= new_A:
                del(a[p]); a[l:l] = [new_A]; continue
            elif a[r0+j-1] <= new_A:
                del(a[p]); a[r0+j:r0+j] = [new_A]; continue   
            while sig < 1:
                m = int((l+r0)/2)
                if a[m] > new_A:
                    r0 = m
                elif a[m+1] < new_A:
                    l = m+1
                else:
                    del(a[p]); a[m+1:m+1] = [new_A]                
                    sig = 1

elif revlad > 0:
    l, r, Qu = q[0][0], q[0][1], int((k+5)/5)
    a[l:r+1] = sorted(a[l:r+1])
    for i in range(1, Q):
        l, r, l0, m, sig = q[i][0], q[i][1], q[i-1][0], 0, 0
        if k > r: break
        if r < l0:
            a[l:r+1] = sorted(a[l:r+1]); continue        
        count = list(range(l, l0))
        for j in range(len(count)):
            p, new_A = count[j], a[count[j]]
            if a[l0] >= new_A:
                del(a[p]); a[l0:l0] = [new_A]; continue
            elif a[r] <= new_A:
                del(a[p]); a[r:r] = [new_A]; continue   
            while sig < 1:
                m = int((l0+r)/2)
                if a[m] > new_A:
                    r = m
                elif a[m+1] < new_A:
                    l0 = m+1
                else:
                    del(a[p]); a[m+1:m+1] = [new_A]                
                    sig = 1
    
elif span_q < 1e9 and a != b:
    for i in count:
        l, r = q[i][0], q[i][1]
        a[l:(r+1)] = sorted(a[l:(r+1)])
else:
    a[pmin:qmax+1] = sorted(a[pmin:qmax+1])   
print(a[k])
