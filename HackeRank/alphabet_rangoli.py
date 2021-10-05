def print_rangoli(n):
    from string import ascii_lowercase as chars
    heap = [(('-'.join(chars[i:n])[::-1]+'-'.join(chars[i:n])[1:])).center(4*n-3, '-')for i in range(n)]
    print(*(heap[::-1]+heap[1:]), sep="\n")
if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
