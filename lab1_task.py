def evaluatePostfix(value):
    stack = []
    maxSize = 5  # Maximum stack size

    for char in value:
        if char.isdigit():  # If char is a number
            if len(stack) >= maxSize:  # Check stack size before pushing
                print("Error: Stack overflow")
                return None
            stack.append(int(char))
        else:  # If char is an operator
            if len(stack) < 2:  # Check for underflow (need at least 2 elements to pop)
                print("Error: Stack underflow")
                return None
            
            # POP operation
            num2 = stack.pop()  
            num1 = stack.pop()

            # Perform the operation
            if char == '+':
                result = num1 + num2
            elif char == '-':
                result = num1 - num2
            elif char == '*':
                result = num1 * num2
            elif char == '/':
                if num2 == 0:
                    print("Error: Division by zero")
                    return None
            else:
                print(f"Error: Unsupported operator: '{char}'")
                return None

            # Push the result back onto the stack
            stack.append(result)

    # Check if there is exactly one result left in the stack
    if len(stack) == 1:
        return stack.pop()
    else:
        print("Error: Invalid postfix expression")
        return None


postfixExpression = input("Enter the postfix expression: ").split()

# Evaluate the postfix expression
result = evaluatePostfix(postfixExpression)

if result is not None:
    print("Result:", result)
