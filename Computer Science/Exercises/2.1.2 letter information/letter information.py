fletters = {}
lletters = {}
fletterslen = {}
lletterslen = {}
summm = 0
averagelen = 0
import codecs
#hand = codecs.open('words.txt', 'w', 'utf-8')
hand = open('russian.txt')
for line in hand:
    line.strip()
    fletters[line[0].upper()] = fletters.get(line[0].upper(), 0) + 1
    fletterslen[line[0].upper()] = fletterslen.get(line[0].upper(), 0) + len(line) - 1
    lletters[line[-2].upper()] = lletters.get(line[-2].upper(), 0) + 1
    lletterslen[line[-2].upper()] = lletterslen.get(line[-2].upper(), 0) + len(line) - 1
    averagelen += len(line) - 1
fletters.pop('-')
fletters.pop('Ь')
fletters.pop('Ъ')
fletters.pop('Ы')
fletterslen.pop('-')
fletterslen.pop('Ь')
fletterslen.pop('Ъ')
fletterslen.pop('Ы')
lletters.pop('-')
lletters.pop('.')
lletterslen.pop('-')
lletterslen.pop('.')
for i in fletters:
    summm += fletters[i]                      #Кол-во слов
averagelen = averagelen / summm


fletterslen
lletterslen
fletters
lletters
summm









fletters_list = list(fletters.keys())
fletters_list.sort()
lletters_list = list(lletters.keys())
lletters_list.sort()
fletterslen_list = list(fletterslen.keys())
fletterslen_list.sort()
lletterslen_list = list(lletterslen.keys())
lletterslen_list.sort()
for i in fletters_list:
    print(fletters[i])
for i in lletters_list:
    print(i, ' ', lletters[i])
for i in fletterslen_list:
    print(fletterslen[i])
for i in lletterslen_list:
    print(lletterslen[i])



fletters
lletters







>>> d = {'a': 10, 'b': 15, 'c': 4}
>>> list_keys = list(d.keys())
>>> list_keys.sort()
>>> for i in list_keys:
...     print(i, ':', d[i])
