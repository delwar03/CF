import math

t = int(input())
for i in range(t):
    _ = input()
    n = int(input())
    print(math.isqrt(n))
    if i != t - 1:
        print("")