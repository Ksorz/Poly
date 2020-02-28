max('Hello')
¤
¬
list.append(x)                 # Добавляет элемент в конец массива.
list.extend(L)                 # Расширяет массив list, добавляя в конец все элементы массива L.
list.insert(i, x)              # Вставляет на i-ый элемент значение x.
list.remove(x)                 # Удаляет первый элемент в массиве, имеющий значение x. ValueError, если такого элемента не существует.
list.pop(i)                    # Удаляет и ВОЗВРАЩАЕТ элемент (i) массива. () - последний элемент.
list.index(x, start , end)     # ВОЗВРАЩАЕТ ПОЛОЖЕНИЕ первого элемента x (поиск ведется от start (включительно) до end (НЕ включительно)).
list.count(x)                  # ВОЗВРАЩАЕТ количество элементов со значением x.
list.sort([key=функция])       # Сортирует массив на основе функции.
list.reverse()                 # Разворачивает массив.
list.copy()                    # Поверхностная копия массива.
list.clear()                   # Очищает массив.

event.speaker.id # Наименование, имя объекта.
len.length

for i in range(len(unit1.id) - 1, -1, -1) # iterate the yetis list in the reverse order.

event.message.toLowerCase() # Перевод текста в нижний регистр, (toUpperCase - верхний).

words = event.message.split(" ") # Разделение текста в массив (words) по ключевым символам: " ", "X" итд.

unitType = words[-1] # Последний элемент массива, ([-2] предпоследний итд).

for x in range(40, 81, 20): # От 40 до 81 с шагом 20.
    hero.moveXY(x, 60) # x1 - 40; x2 - 60; x3 - 80

target = targets.pop(0) # Удаляет и возвращает (target) элемент (0) массива (targets). () - последний элемент.

s = "  \t a string example\t  "
trimmed = string.trim() # string = "   a string example   ", trimmed = "a string example"

variable.type

quit() # Stop executing the program

import os
print(os.getcwd())
os.chdir(r'PATH')
