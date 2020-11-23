import json
import urllib.request, urllib.parse, urllib.error

url = 'http://py4e-data.dr-chuck.net/comments_236685.json'
connection = urllib.request.urlopen(url)
data = connection.read().decode()
js = json.loads(data)
print( sum(i['count'] for i in js['comments']) )
