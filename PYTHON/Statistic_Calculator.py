import scipy.stats as st
import math

# Confidence Interval
def confIntrv(signLevel, mean, sd, n):
    alpha = ((signLevel/100) - 1) * (-1)
    alphaOver2 = alpha / 2
    print(alphaOver2)
    criticalV = round(st.norm.ppf(1-alphaOver2), 2)
    marginE = criticalV * sd / math.sqrt(n)
    return (mean - marginE, mean + marginE)

# Two Sample T-test
# Degree of freedom when standard error is given
def find_df_se(m, n, se1, se2):
    top = ((se1**2) + (se2**2))**2
    bot = ((se1**4)/(m-1)) + ((se2**4)/(n-1))
    return top/bot

# ANOVA
def calAnova(sample2D):

    xidot = []
    xidotbar = []
    xdotdot = 0
    for i in sample2D:
        accu = 0
        for j in i:
            accu += j
        xidot.append(accu)
        xidotbar.append(accu/len(i))
        xdotdot += accu/len(i)
    xdotdot = xdotdot / len(sample2D)

    # SSTr
    sstr = 0
    for i in xidotbar:
        sstr += (i - xdotdot)**2
    sstr = sstr * len(sample2D[0])

    # SSE
    sse = 0
    for i in range(len(sample2D)):
        for j in range(len(sample2D[i])):
            sse += (sample2D[i][j] - xidotbar[i]) ** 2

    # SST
    sst = 0
    for i in sample2D:
        for j in i:
            sst += (j - xdotdot) ** 2
    
    print("Xi. = ", xidot)
    print("Xi.Bar = ", xidotbar)
    print("X.. = ", xdotdot)
    print("SSTr = ", sstr)
    print("SSE = ", sse)
    print("SST = ", sst)

# Estimating model parameter
def find_Sxx_yy(yArr):
    sumYisqr = 0
    for i in yArr:
        sumYisqr += i**2
    sumYi = 0
    for i in yArr:
        sumYi += i
    return sumYisqr - (sumYi**2)/len(yArr)

def find_Sxy(xArr, yArr):
    sumXiYi = 0
    sumXi = 0
    sumYi = 0
    for i in range(len(xArr)):
        sumXiYi += xArr[i] * yArr[i]
        sumXi += xArr[i]
        sumYi += yArr[i]
    return sumXiYi - (sumXi * sumYi) / len(xArr)

def find_SSE(xArr, yArr):
    slope = find_Sxy(xArr, yArr) / find_Sxx_yy(xArr)

    muY = 0
    muX = 0
    for i in range(len(yArr)):
        muY += yArr[i]
        muX += xArr[i]
    muY = muY / len(yArr)
    muX = muX / len(xArr)

    yintrc = muY - slope * muX

    sum = 0

    for i in range(len(xArr)):
        yihat = yintrc + slope * xArr[i]
        sum += (yArr[i] - yihat)**2

    return sum


# Calculate R-Square for linear model
def find_rsqr(xArr, yArr):
    sse = find_SSE(xArr, yArr)
    sst = find_Sxx_yy(yArr)
    return 1 - sse / sst
