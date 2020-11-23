# 11.1 - Regular Expressions
hand = open('mbox-short.txt')
for line in hand:
    line.strip()
    if line.find('From: ') >= 0: # Variable name.method
        print(line)

import re
hand = open('mbox-short.txt')
for line in hand:
    line.strip()
    if re.search('^X-\S+Type', line): # Library name.function
        print(line)

# 11.2 - Extracting Data
import re
x = 'My 2 favorite numbers are 49 and 114'
y = re.findall('[0-9]+', x)
print(y)

x = 'From: using the: char'
print( re.findall('^F.+:', x) ) # ['From: using the:'] Greedy
print( re.findall('^F.+?:', x) ) # ['From:'] Not greedy

x = open('mbox-short.txt')
for line in x:
    line.strip()
    if len(re.findall('^From (\S+@\S+)', line)) > 0:
        print( re.findall('^From (\S+@\S+)', line) )  # print something non-blank'@'non-blank after 'From' but not including 'From'
        print( re.findall('@([^ ]*)', line) ) # after '@' match non-blank [^ ] match any of them *
        print( re.findall('From .*@([^ ]*)', line) )

# 12.2 - Hypertext Transfer Protocol (HTTP)
import socket
mysock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
mysock.connect( ('data.pr4e.org', 80) ) # 'data.pr4e.org' - host; 80 - port (tuple)
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\r\n\r\n'.encode() # encode coverts Unicode to UTF-8
mysock.send(cmd)
while True:
    data = mysock.recv(512)
    if (len(data) < 1):
        break
    print(data.decode()) # decode converts UTF-8 to Unicode
mysock.close()

# 12.4 - Retrieving Web Pages
import urllib.request, urllib.parse, urllib.error
fhand = urllib.request.urlopen('http://data.pr4e.org/romeo.txt') # Parse the URL. what server to talk to, what document to retrieve, HTTP version, GET request, all that stuff. (Almost the same as open(file))
print(fhand)
for line in fhand:
    print(line.decode().strip()) # line is byte array (not str), so we .decode() it.

# 12.5 - Parsing Web Pages
import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
_adress = input('enter:')
fhand = urllib.request.urlopen(_adress).read() # document at that web page in a single big string with a /n in the end of each line
sp = BeautifulSoup(fhand, 'html.parser') # sp is soup object with anchor tags
tags = sp('a') # retreive all the 'a' anchor tags in document
tags
for tag in tags:
    print(tag.get('href', None)) # prints out href='THIS TEXT' or None (href key)

# 13.4 - Parsing XML
import xml.etree.ElementTree as ET
data = '''<person>
  <name>Chuck</name>
  <phone type="intl">
    +1 734 303 4456
    </phone>
    <email hide="yes"/>
</person>''' # '''   ''' triple quotes means multi-line string
tree = ET.fromstring(data) # .fromstring says convert this (data) string and give us tree
print('Name:', tree.find('name').text) # within that (tree) XML data go find the tag 'name'
print('Attr:', tree.find('email').get('hide'))

# 13.7 - Using Application Programming Interfaces
import urllib.request, urllib.parse, urllib.error
import json

api_key = 42
serviceurl = 'http://py4e-data.dr-chuck.net/json?'

while True:
    address = input('Enter location: ')
    if len(address) < 1: break

    parms = dict()
    parms['address'] = address
    parms['key'] = api_key
    url = serviceurl + urllib.parse.urlencode(parms)

    print('Retrieving', url)
    uh = urllib.request.urlopen(url) # Get url header
    data = uh.read().decode() # decode and read json data
    print('Retrieved', len(data), 'characters')
    headers = dict(uh.getheaders()) # get headers from .urlopen
    # print(headers)

    try:
        js = json.loads(data) # parse json data into python-understanable format
    except:
        js = None

    if not js or 'status' not in js or js['status'] != 'OK':
        print('==== Failure To Retrieve ====')
        print(data)
        continue
    # print(json.dumps(js, indent=4)) # JSON body as str

    lat = js['results'][0]['geometry']['location']['lat']
    lng = js['results'][0]['geometry']['location']['lng']
    print('lat', lat, 'lng', lng)
    location = js['results'][0]['formatted_address']
    print(location)
