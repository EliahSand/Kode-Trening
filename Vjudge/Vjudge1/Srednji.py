from collections import defaultdict

def count_subsequences_with_median_B(n, B, A):
    # Find the position of B in the array
    pos = A.index(B)
    
    # Dictionary to count occurrences of different sums
    balance_count = defaultdict(int)
    balance_count[0] = 1  # Initialize with the balance 0
    
    sum = 0
    
    # Count subsequences on the right side of B
    for i in range(pos + 1, n):
        if A[i] > B:
            sum += 1
        else:
            sum -= 1
        balance_count[sum] += 1
    
    result = balance_count[0]
    sum = 0
    
    # Count subsequences on the left side of B
    for i in range(pos - 1, -1, -1):
        if A[i] > B:
            sum += 1
        else:
            sum -= 1
        result += balance_count[-sum]
    
    return result

def main():
    

    n,B = map(int, input().split())
    
    # Read the second line values
    A = list(map(int, input().split()[2:2 + n]))
    
    # Compute the result
    result = count_subsequences_with_median_B(n, B, A)
    
    # Output the result
    print(result)

main()

