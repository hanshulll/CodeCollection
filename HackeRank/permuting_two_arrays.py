def isGood(listA, listB, k):
    n = len(listA)
    listA.sort()
    listB.sort(reverse=True)
    for i in range(n):
        if listA[i]+listB[i] < k:
            return False
    return True

T = int(input().strip())
for i in range(T):
    [n, k] = [int(x) for x in input().strip().split()]
    listA = [int(x) for x in input().strip().split()]
    listB = [int(x) for x in input().strip().split()]
    if isGood(listA, listB, k):
        print("YES")
    else:
        print("NO")
