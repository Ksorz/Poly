"""
Имеется алгоритм, описанный словесно.

• Положить в вазочку N конфет.
• Загнуть на левой руке 3 пальца.
• Бросить монетку на стол.
• Если выпал орёл, увеличить количество конфет в вазочке в А раз, иначе добавить в вазочку В конфет.
• Разогнуть один палец на левой руке.
• Если на левой руке остались загнутые пальцы, перейти к п.3.
Вовочка многократно выполнял этот алгоритм при N=11 (ну нравится ему это число!). В результате примерно с равной вероятностью он получал 26, 32, 37, 42, 49, 54, 64 и 88 конфет в вазочке. А какие значения он бы получил при N=5?
Ответ сформулируйте таким образом, как будто объясняете решение задачи двоечнику-восьмикласснику, которому Вы приходитесь репетитором. Ответ оформите в виде файла MS Word, наличие иллюстраций приветствуется. Излагать теорию вероятности не нужно.
"""


import random
result = {}

def candys(N):
    for i in range(3):
        if random.randint(0, 1) == 0:
            N *= 2
        else:
            N += 5
    return N

for i in range(10000):
    var = candys(5)
    if var in result:
        result[var] += 1
    else:
        result[var] = 1

result_keys = list(result.keys())
result_keys.sort()
for i in result_keys:
    print(i, '->', result[i])