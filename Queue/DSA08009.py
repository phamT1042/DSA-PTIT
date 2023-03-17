
def solve (s, t):
    queue = [[s, 0]] #<giá trj, số bước đến giá trị này từ s>
    checkSet = {s}
    while len(queue):
        i = queue[0][0]
        j = queue[0][1]
        queue.pop(0)
        if i * 2 not in checkSet:
            if i * 2 == t: return j + 1
            elif i < t:
                queue.append([i * 2, j + 1])
                checkSet.add(i * 2)
        if i - 1 not in checkSet and i - 1 > 0: 
            if i - 1 == t: return j + 1
            else:
                queue.append([i - 1, j + 1])
                checkSet.add(i - 1)
    return 0

T = int(input())
while T > 0:
    T -= 1
    s, t = map(int, input().split())
    print(solve(s, t))