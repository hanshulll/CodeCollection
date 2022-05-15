def generateParentheses(openBr, closeBr, n, s = []):
    global k
    if k<n:
        if closeBr == n:
            k+=1
            print(''.join(s))
            return 

        if closeBr < openBr:
            s.append(')')
            generateParentheses(openBr, closeBr+1, n, s)
            s.pop()
        if openBr < n:
            s.append('(')
            generateParentheses(openBr+1, closeBr, n, s)
            s.pop()
        return


t = int(input())
while t>0:
    k =0
    n = int(input())
    generateParentheses(0, 0, n)
    t-=1