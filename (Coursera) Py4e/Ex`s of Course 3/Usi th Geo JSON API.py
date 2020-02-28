import urllib.request, urllib.parse, urllib.error
import json


api_key = 42
serviceurl = 'http://py4e-data.dr-chuck.net/json?'


address = input('Enter location: ')
parms = dict()
parms['address'] = address
parms['key'] = api_key
url = serviceurl + urllib.parse.urlencode(parms)
uh = urllib.request.urlopen(url)
data = uh.read().decode()
js = json.loads(data)
print(js['results'][0]['place_id'])
