MOD = 123456789

def demday(n):
    if n == 0: return 1
    tmp = demday(n // 2) % MOD
    if n % 2 == 0: return (tmp * tmp) % MOD
    return (tmp * tmp * 2) % MOD

t = int(input())
while (t > 0):
    t -= 1
    n = int(input())
    print(demday(n - 1))
