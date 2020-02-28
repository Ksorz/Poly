# 7.2 --------------------------------
x = open('learned_cmd.txt')
for i in x:
    print(i.rstrip())
x = open('learned_cmd.txt')
y = x.read()
print(y)
# 8.1 --------------------------------
range(4)
x = [1, 1, 'lol', 777]
for i in range(len(x)):
    print(i, x[i])
# 8.2 --------------------------------
friends = [ 'Joseph', 'Glenn', 'Sally' ]
friends.sort()
print(friends[0]) # Glenn
x = [1, 3, 2]
y = ['y', 21, 4]
x + y # [1, 3, 2, 'y', 21, 4]
sum(x) # 6
# 9.1 --------------------------------
pur = dict() # = {}
pur['money'] = 112
pur['honey'] = 'empty'
pur['money'] = pur['money'] + 100
pur[551] = 'carrot'
pur # {551: 'carrot', 'money': 212, 'honey': 'empty'}
# 9.2 --------------------------------
if 'money' in pur:
    x = pur['money']
else:
    x = 0
x = pur.get('money', 0) # .get is equal to conditional code above. x == 212
# 9.3 --------------------------------
print(list(pur), '\n')
print(pur.keys(), '\n')   # keys and values orders do correspond
print(pur.values(), '\n') # values and keys orders do correspond
print(pur.items(),)       # a list of tuples
x = open('mbox-short.txt')
count = {}
for line in x:
    line = line.split()
    for word in line:
        count[word] = count.get(word, 0) + 1
often = {}
for i in count:
    x = count.get(i)                # x == count.get(i) == count[i]
    if x > 100:
        often[i] = often.get(i, x)  # x == count.get(i) == count[i]
for i, j in often.items():          # i is key, j is value
    print(i, j)
# 10 ---------------------------------
d = {'a': 12, 'b': 3, 'c': 41, 'd': 100}
tmp = list()
for k, v in d.items():
    tmp.append((v, k)) # [(12, 'a'), (3, 'b'), (41, 'c'), (100, 'd')]
sorted(tmp, reverse = True) # [(100, 'd'), (41, 'c'), (12, 'a'), (3, 'b')]
file = open('mbox-short.txt')
d = {}
for line in file:
    line = line.split()
    for word in line:
        d[word] = d.get(word, 0) + 1

print( sorted( [(v, k) for k, v in d.items()], reverse = True )[:5] ) #         <-----------! List comprehension
# [(352, 'Jan'), (324, '2008'), (245, 'by'), (243, 'Received:'), (219, '-0500')]
tmp = []
for k, v in d.items():
    tmp.append((v, k))
tmp.sort(reverse = True)
tmp[:5] # [(352, 'Jan'), (324, '2008'), (245, 'by'), (243, 'Received:'), (219, '-0500')]
for v, k in tmp[:5]:
    print(k, v)
