t = int(input())
while (t > 0):
    t -= 1
    n = int(input())
    list_res = ["6", "8"]
    queue = ["6", "8"]
    while 1:
        front = queue[0]
        queue.pop(0)
        if len(front) < n:
            list_res += [front + "6", front + "8"]
            queue += [front + "6", front + "8"]
        else:
            break
    print(len(list_res))
    for i in list_res:
        print(i, end = " ")
    print("")
