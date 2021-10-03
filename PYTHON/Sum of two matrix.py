def inp(rows,column):
    matrix_a= [[int(input()) for i in range(column)] for i in range(rows)]
    return (matrix_a)

def out(m):
    for n in m:
        print(n)

def cal(rows,column,m,n):
    result=[[0 for i in range(column)] for i in range(rows)]
    for i in range(rows):
        for j in range(column):
            result[i][j] = m[i][j]+n[i][j]
    print("The Sum of Above two Matrices is : ")
    for r in result:
        print(r)
rows = int(input("Enter the Number of rows : " ))
column = int(input("Enter the Number of Columns: "))
print("Enter the elements of First Matrix:")
a=inp(rows,column)
print("Enter the elements of Second Matrix:")
b=inp(rows,column)
print("First Matrix is:")
out(a)
print("Second Matrix is:")
out(b)
cal(rows,column,a,b)
