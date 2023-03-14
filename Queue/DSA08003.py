t = int(input())
queue = []
while(t > 0):
    t -= 1
    s = input()
    if s[1] == 'U':
        if s[4] == 'F': queue.insert(0, s[10:])
        else: queue.append(s[9:])
    elif s[1] == 'O':
        if len(queue) > 0: 
            if s[3] == 'F': queue.pop(0)
            else: queue.pop()
    else:
        if (len(queue) > 0): 
            if s[5] == 'F': print(queue[0])
            else: print(queue[-1])
        else: print("NONE")