import urllib.request, urllib.parse, urllib.error
import xml.etree.ElementTree as ET

_data = urllib.request.urlopen('http://py4e-data.dr-chuck.net/comments_236684.xml').read()
_tree = ET.fromstring(_data)
_counts = _tree.findall('.//count')
print( sum(int(i.text) for i in _counts) )
