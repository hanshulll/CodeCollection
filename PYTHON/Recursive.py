

#Consider the following recursive sequence of numbers:

#1,2,4,7,11. . . .
#Sample Output:

#Enter number:1
#Output:1
#Enter number:2
#Output:2
#Enter number:3
#Output:4
#Enter number: -1
#Output: Finished


#function start
def funcion1(n):
    if n == 1:
        return 1
    else:
        return n - 1 +funcion1(n - 1)

n = int(input("Enter the n :"))
while n!= -1:
    print(funcion1(n))
    n = int(input("Enter the n :"))

print("Finished") #exit
