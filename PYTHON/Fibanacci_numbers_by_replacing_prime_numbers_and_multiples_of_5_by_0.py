def is_prime(n):
    if n > 1:
        for i in range(2, n // 2 + 1):
            if (n % i) == 0:
                return False
        else:
            return True
    else:
        return False

def fibonacci(n):
    n1, n2 = 1, 1 
    count = 0

    if n == 1:
        print(n1)
    else:
        while count < n:
            if not is_prime(n1) and n1 % 5 != 0:
                print(n1, end=' ')
            else:
                print(0, end=' ')
            n3 = n1 + n2
            n1 = n2
            n2 = n3
            count += 1 

n = int(input("Enter the number:"))
fibonacci(n)
