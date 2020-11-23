n = 20 # Условие задачи СТРОКИ  20
m = 19 # Условие задачи СТОЛБЦЫ 19
k = 1
mas = [[0]] * n
for i in range(len(mas)):
    mas[i] = mas[i] * m

while True:
    if k <= n:
        mas[k-1][0] = k
        j = 2

        while True:
            if j <= m:
                mas[k-1][j-1] = k*j - mas[k-1][j-2]
                j += 1
            else:
                k += 1
                break
    else: break

count = 0
for i in range(len(mas)):
    for j in range(len(mas[i])):
        if mas[i][j] % 2 == 0:
            count += 1

print('Количество чисел в массиве: ' + str(len(mas) * len(mas[0])))
print('Количество чётных чисел в массиве: ' + str(count) + '\n')

for i in range(len(mas)):
    print(mas[i])
