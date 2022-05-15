import sys
def fastfib(n):
    
    if n <= 1:
        return n
    elif n == 2:
        return 1
    else:
        a = [0,1]
        for i in range(2, n+1):
            a.append((a[i-1] + a[i-2])%10)
        return a[n]

if __name__ == "__main__":
    # input = sys.stdin.read();
    # n = map(int, input())
    n = int(input())
    print(fastfib(n))
# showing str error