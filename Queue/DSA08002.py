t = int(input())
queue = []
while(t > 0):
    t -= 1
    s = input()
    if s[1] == 'U': queue.append(s[5:])
    elif s[1] == 'O':
        if (len(queue) > 0): queue.pop(0)
    else:
        if (len(queue) > 0): print(queue[0])
        else: print("NONE")