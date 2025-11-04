def fibonacci_iterative(n):
    a, b = 0, 1
    for _ in range(n):
        print(a, end=" ")
        a, b = b, a + b

# Example: print first 10 Fibonacci numbers
fibonacci_iterative(10)


def fib_recursive(n):
    if n <= 1:
        return n
    else:
        return fib_recursive(n-1) + fib_recursive(n-2)

# Print first 10 Fibonacci numbers
for i in range(10):
    print(fib_recursive(i), end=" ")

    