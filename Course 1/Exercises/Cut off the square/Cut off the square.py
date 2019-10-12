A = 2
B = 3
tmp = None

for i in range(int(input('Enter number of iterations: '))):
    tmp = B
    B = A + B
    A = tmp

print(A, B)
