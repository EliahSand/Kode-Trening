def median(numbers):
    sorted_numbers = sorted(numbers)
    length = len(sorted_numbers)
    mid = length // 2
    
    if length % 2 == 0:
        return (sorted_numbers[mid - 1] + sorted_numbers[mid]) / 2
    else:
        return sorted_numbers[mid]

# Example usage
numbers = [5, 2, 9, 1, 7, 6, 3]
result = median(numbers)
print(f"The median is: {result}")



