def process_mountain(m, arr, stack, max_jump):
    max_j_at_m = 0
    while stack and arr[m] >= stack[-1][0]:
        max_j_at_m = max(arr[m] - stack[-1][0] + stack[-1][1], max_j_at_m)
        stack.pop()
    
    stack.append((arr[m], max_j_at_m))
    max_jump[0] = max(max_jump[0], max_j_at_m)

def jumpdistance(n, arr):
    if n < 2:
        return 0

    max_h = arr[0]
    max_h_pos = 0
    
    for i in range(1, n):
        if arr[i] > max_h:
            max_h = arr[i]
            max_h_pos = i

    stack = [(max_h, 0)]
    max_jump = [0]  
    
    for i in range(max_h_pos - 1, -1, -1):
        process_mountain(i, arr, stack, max_jump)
    

    stack = [(max_h, 0)]
    for i in range(max_h_pos + 1, n):
        process_mountain(i, arr, stack, max_jump)

    return max_jump[0]

n = int(input())
høyder = list(map(int, input().split()))

print(jumpdistance(n,høyder))

