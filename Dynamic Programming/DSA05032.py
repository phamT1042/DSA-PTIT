t = int(input())
while t > 0:
    t -= 1
    s = input()
    n = len(s)
    dp = [[0 for i in range(n)] for j in range(n)]
    for i in range(n - 2, -1, -1):
        for j in range(i + 1, n):
            if s[i] == s[j]: dp[i][j] = dp[i + 1][j - 1]
            else: dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1
    print(dp[0][n - 1])