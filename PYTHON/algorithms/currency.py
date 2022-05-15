try:
    tc = int(input())
    
    for i in range(tc):
        currency = [100,50,10,5,2,1]
        amount = int(input())
        count = 0

        for i in currency:
            if amount>1:
                count = count+(amount//i)
                amount = amount%i
        print(count)

except:
    pass