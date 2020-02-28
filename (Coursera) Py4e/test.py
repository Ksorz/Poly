def f(x):
  return (x - 16)*(x + 43)

a = -100
b = 10
n = 0
for t in range(a, b + 1):

    if (t - 16)*(t + 43) <= 0:
        n = n + 1

print(n)
