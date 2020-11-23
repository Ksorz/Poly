import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import re

_url = input('Enter URL: ')
_count = int(input('Enter count: '))
_position = int(input('Enter position: '))
soup = BeautifulSoup(urllib.request.urlopen(_url), 'html.parser')

for i in range(_count + 1):
    print(soup.find_all(string=re.compile('People that '), limit = 1))
    soup = BeautifulSoup(urllib.request.urlopen(soup('a')[_position - 1].get('href')), 'html.parser')

# .find_all(re.compile("that (\S.*\S)"))
