def fibonacci_list(n):
    if n<=0:
        return []

    result = []
    a = 0
    b = 1

    for i in range(n): #loops for n times for n numbers

        result.append(a) #fbonacci number in result
        a, b = b, a+b

    return result

print(fibonacci_list(10))
