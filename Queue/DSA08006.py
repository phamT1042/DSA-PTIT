t = int(input())
while (t > 0):
    t -= 1
    n = int(input())
    queue = ["9"]
    while (1):
        if (int(queue[0]) % n == 0):
            print(queue[0])
            break 
        queue.append(queue[0] + "0")
        queue.append(queue[0] + "9")
        queue.pop(0)
