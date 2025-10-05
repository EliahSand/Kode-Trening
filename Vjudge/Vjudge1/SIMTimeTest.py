import time

# Generate a test string of length 10^5
# You can adjust the pattern of the string to test different scenarios.
test_string = '[' * 50000 + 'a' * 50000 + ']' * 50000  # Example: This string will test cursor movement heavily

# Number of test cases
T = 1  # Just one test case since we're focusing on performance for a large input

start_time = time.time()  # Start timing

# Process the test case
T = int(input())


for _ in range(T):
    #line = input()
    result = []
    cursor = 0  # Simulates the cursor position

    for ch in test_string:
        if ch == '[':
            cursor = 0  # Move cursor to the start
        elif ch == ']':
            cursor = len(result)  # Move cursor to the end
        elif ch == '<':
            if cursor > 0:
                cursor -= 1
                result.pop(cursor)  # Remove the character before the cursor
        else:
            result.insert(cursor, ch)  # Insert character at the cursor
            cursor += 1  # Move cursor to the right after insertion

    print(''.join(result))



end_time = time.time()  # End timing

# Output the result and the time taken
print("Processed result length:", len(result))  # Just to confirm that the process completed
print("Time taken: {:.5f} seconds".format(end_time - start_time))
