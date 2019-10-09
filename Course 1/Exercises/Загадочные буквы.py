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
