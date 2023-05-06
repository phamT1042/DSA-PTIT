'''k = p1^a1 * p2^a2 * ... * pn^an thi n = (a1 + 1)(a2 + 1)...(an+1)'''
prime = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
def Try (i, k, soUoc):
    if soUoc > n: return
    global res
    if soUoc == n: res = min(res, k)
    j = 1
    while k * prime[i] <= res:
        k *= prime[i]
        Try(i + 1, k, soUoc * (j + 1))
        j += 1

t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    res = 1e18
    Try(0, 1, 1)
    print(res)