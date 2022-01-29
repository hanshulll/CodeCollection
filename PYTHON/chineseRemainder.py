'''
Here we look at the python code for implementing the Chinese Remainder Theorem
Given,
        x = a1 (mod n1)
        x = a2 (mod n2)
        x = a3 (mod n3)
With gcd(n1,n2) = gcd(n1,n3) = gcd(n2,n3) = 1
        -All the n-values are coprime with the others
We have N = n1*n2*n3 and
        N1 = n2*n3
        N2 = n1*n3
        N3 = n1*n2
Summaring, the Ni values are composed multiplying all
the n-values each others, except n at position i
Ending, we call yi the solutions of Ni*yi = 1 (mod ni)
        Ex: N1 * y1 = 1 (mod n1)
Now, we have to find the value of integer a such that:
        x = a (mod N)
Knowing also that:
        x = a1N1y1 + a2N2y2 + a3N3y3 (mod N)
Easy, no?
'''

from Crypto.Util.number import inverse

A = [2,3,5]
# Example array consisting of a1,a2,a3

n = [5,11,17]
## Example array consisting of n1,n2,n3

length = len(A)
product = 1

for i in n:
    product *= i

N = []
for i in range(len(A)):
    J = int(product/n[i])
    N.append(J)

Y = []
for i in range(len(A)):
    J = inverse(N[i], n[i])
    Y.append(J)

a = 1
for i in range(len(A)):
    a += A[i]*N[i]*Y[i]

a %= product
print(a)
