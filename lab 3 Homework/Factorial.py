def fact(n):
  if n == 1 or n == 0:
    return 1
  elif n<0:
    print(f"The factorial of {n} is not defined.")
    return None
  else:
    return n * fact(n-1)
n = int(input("enter a number: "))
result = fact(n)

if result is not None:
 print(f"The factorial of the number is: {result}")
