import subprocess
from itertools import permutations

def generate_permutations(nums):
    return list(permutations(nums))

def count_movements_for_input(c_program_path, input_nums):
    # Run the C program with the given input numbers and capture its output
    result = subprocess.run([c_program_path] + list(map(str, input_nums)), capture_output=True, text=True)
    output = result.stdout

    # Count the number of lines (movements) in the output
    return len(output.strip().split('\n'))

# Example usage:
c_program_path = './push_swap'  # Change this to the path of your C program executable if needed
nums = [1, 2, 3, 4, 5]
all_permutations = generate_permutations(nums)

for p in all_permutations:
    count = count_movements_for_input(c_program_path, p)
    print(f"Combination {p} - {count} movements")
