 # 5 - ТУР, 2 - БОК, 7 - ?
x = int(input('Enter number: '))

if x % 2 == 1:
    print('Т')
else:
    print('Б')

x = x // 2 # Целочисленное деление

if x % 2 == 1:
    print('О')
else:
    print('У')

x = x // 2

if x % 2 == 1:
    print('Р')
else:
    print('К')

y = 7
print('y = ' + str(y))
print('y % 2 = ' + str(y % 2) + '\n')
y = y // 2
print('y = ' + str(y))
print('y % 2 = ' + str(y % 2) + '\n')
y = y // 2
print('y = ' + str(y))
print('y % 2 = ' + str(y % 2))
