# 1.12.9. Из последовательности натуральных чисел удалили все числа, делящи-еся на 3, а затем удалили все числа, делящиеся на 7. Какое число стоит на 70-м месте?
import math
x = 72; x1 = 3; x2 = 7
y = x1 * x2 - x1 - x2 + round(x2/x1) - 1
z = x1 * x2 - y

index = 0
for i in range(15000):
    if ((i + 1) / 3).is_integer() or ((i + 1) / 7).is_integer():
        continue
    index += 1
    if index == x: print(i+1)
math.floor(x/y) * z
print((y * (x/y)) + (z * (x/y)))






70%12
