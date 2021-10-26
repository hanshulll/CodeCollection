def largestSubset(a, n):
    dp = [0 for i in range(n)]
    dp[n - 1] = 1;
    for i in range(n - 2, -1, -1):
        mxm = 0;
        for j in range(i + 1, n):
            if a[j] % a[i] == 0 or a[i] % a[j] == 0:
                mxm = max(mxm, dp[j])
        dp[i] = 1 + mxm
    return max(dp)
a = [ 1, 3, 6, 13, 17, 18 ]
n = len(a)
print(largestSubset(a, n))
