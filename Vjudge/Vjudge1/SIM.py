T = int(input())

for _ in range(T):
    line = input()
    left = []  
    right = []  
    
    for ch in line:
        if ch == ']':
            while right:
                left.append(right.pop())
        elif ch == '[':
            while left:
                right.append(left.pop())
        elif ch == '<':
            if left:
                left.pop()
        else:
            left.append(ch)
    
    result = ''.join(left + right[::-1])
    print(result)
