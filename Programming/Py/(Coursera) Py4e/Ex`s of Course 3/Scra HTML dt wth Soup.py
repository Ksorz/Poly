from urllib.request import urlopen
from bs4 import BeautifulSoup

html = urlopen('http://py4e-data.dr-chuck.net/comments_236682.html').read()
soup = BeautifulSoup(html, "html.parser")
tags = soup('span')
print(sum([int(tag.contents[0]) for tag in tags]))
