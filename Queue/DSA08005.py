t = int(input())
while (t > 0):
    t -= 1
    n = int(input())
    n = bin(n)[2:]
    queue = ["1"]
    while (1):
        print(queue[0], end = ' ')
        if (queue[0] == n): break
        queue.append(queue[0] + "0")
        queue.append(queue[0] + "1")
        queue.pop(0)
    print("")
