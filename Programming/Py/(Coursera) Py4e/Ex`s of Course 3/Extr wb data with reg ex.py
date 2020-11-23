import re
print(sum([ int(i) for i in re.findall('[0-9]+', open('regex_sum_236680.txt').read() )]))

x = open('regex_sum_236680.txt')
import re
sm = 0
for i in x:
    if len(re.findall('[0-9]+', i)) > 0:
        for i in re.findall('[0-9]+', i):
            sm = sm + int(i)
print(sm)
