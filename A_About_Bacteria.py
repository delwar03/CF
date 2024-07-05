k, b, n, t = map(int, input().split())

m = 0
if k == 1:
    z = n * b
    while z > t + m * b:
        m += 1
else:
    val = ((k - 1) * t + b) / (k - 1 + b)
    p = pow(k, n - m)
    while p > val:
        m += 1
        p = pow(k, n - m)

print(m)