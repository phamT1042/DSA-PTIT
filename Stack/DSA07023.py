t = int(input())
while(t > 0):
    t -= 1
    s = list(map(str, input().split()))
    s.reverse()
    for i in s: print(i, end = ' ')
    print('')