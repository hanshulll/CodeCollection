#---Fibonacci recursive python function---
def Fibonacci(n):
    if n<=1 :
        return n
    else :
        #recursive function
        return Fibonacci(n-1)+Fibonacci(n-2)


#---main---
n = int(input("Input an integer: ")) #get the number

while n!=-1: #checking if input value is not equal to -1
    #if input is not equals to -1 
    Fibonacci(n) #pass it to the function
    print("Output is",Fibonacci(n))
    #asking user to input another integer value
    n = int(input("Input an integer: ")) #get the number
