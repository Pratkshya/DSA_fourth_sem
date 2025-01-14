# Initialize a table to store computed Fibonacci values
table = [-1] * 1000

def Fibo(n):
    # Base case
    if n == 1 or n == 2:
        return 1
    else:
        # If the value is not computed yet, calculate it
        if table[n] == -1:
            table[n] = Fibo(n - 1) + Fibo(n - 2)
        return table[n]

# Initialize the table
table = [-1] * 1000

# Take input from the user
n = int(input("Enter a number: "))

# Call the Fibonacci function and print the result
print(f"Answer is: {Fibo(n)}")
