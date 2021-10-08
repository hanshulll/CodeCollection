list = [10,12,24,68,21,45]

mx = max(list[0], list[1])
secondmax = min(list[0], list[1])

n=len(list)
for i in range(2,n):
    if list[i]>mx:
        secondmax = mx
        mx = list[i]
    elif list[i]>secondmax and \
        mx != list[i]:
        secondmax = list[i]
print("Second highest number is:", str(secondmax))
