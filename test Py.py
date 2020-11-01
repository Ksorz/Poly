import math
n = 4
k = 3
l = 0
for i in range(round(math.factorial(n)/(math.factorial(k)*math.factorial((n-k))))):
    if i % k == 0:
        l += 1
    d = 0
    for j in range(k):

        print(j + l - 1 + d, end=' ')
        d += 0
    print()









    print(i+1)
