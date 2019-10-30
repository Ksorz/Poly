D = 0
C = 0
N = int(input("N"))
M = int(input("M"))

while True:
    if N > 0:
        X = int(input("X"))
        if X > M:
            C += 1
        elif C > D:
            D = C
        else:
            C = 1

    elif C > D:
        D = 0
    else:
        print(D)
        break
    M = X
    N -= 1















7x = 2
y = 3
for i in range(666):
    if x <= y:
        x += 1
    else:
        y += 1
print(x, y)

















3N = 10
while N > 0:
    if N % 3 == 0:
        print("ОХ!")
    if N % 5 == 0:
        print("УХ!")
    if N % 7 == 0:
        print("АЙ!")
    N = N - 1




M = 2013
N = 1
D = 10
while M >= D:
    N = N + 1
    D = D * 10

print(N)





N = 333
P = 2
while N>0:
    K = 2
    while K<P:
        if P % K == 0:
            break
        K = K+1

    if P % K > 0:
        print(P)
    N = N-1

    P=P+1








N = 322
a = 2
b = 3
while N>0:
    a = a*b
    B = a+1
    print(b)
    N = N-1











N = 99
for K in range(1, N):
    print(K*K + 41*K + 1)







N = 121
for k in range(1, N):

    L = k*9
    S = 0
    while L>0:

        S = S + L % 10
        L = L // 10*k
        if S<10:
            break
        L = S

    print(S*(S-5) + 1)
