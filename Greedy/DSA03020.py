t = int(input())
while t > 0:
    t -= 1
    s = input()
    swap = cnt = 0
    stack = []
    for i in range(0, len(s)):
        if stack == []:
            stack.append(i)
            cnt = 0
        elif s[stack[-1]] == '[' and s[i] == ']':
            cnt += 2
            stack.pop()
        elif s[stack[-1]] == ']' and s[i] == '[':
            swap += len(stack) + cnt
            stack.pop()
        else:
            stack.append(i)
    print(swap)