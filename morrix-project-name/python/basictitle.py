#!/usr/bin/env python

# Basic HTML Title Retriever - Chapter 7 - basictitle.py
# http://bbs.fudan.sh.cn/bbs/doc?bid=523
from HTMLParser import HTMLParser
import sys,urllib2

class TitleParser(HTMLParser):
	def __init__(self):
		self.title = ''
		self.readingtitle = 0
		HTMLParser.__init__(self)

	def handle_starttag(self, tag, attrs):
 		if tag == 'title':
			self.readingtitle = 1

	def handle_data(self, data):
		if self.readingtitle:
			# Ordinarily, this is slow and a bad practice, but
			# we can get away with it beccause a title is usually
			# small and simple.
			self.title += data

	def handle_endtag(self, tag):
		if tag == 'title':
			self.readingtitle = 0

	def gettitle(self):
		return self.title


req = urllib2.Request(sys.argv[1])

print "argv[1]=", sys.argv[1]

fd = urllib2.urlopen(req)
while 1:	# loop statement, end with ':'
	data = fd.read(1024)
	if not len(data):	# if statment, end with ':', same as loop
		break;
	sys.stdout.write(data)

#fd = open(sys.argv[1])
tp = TitleParser()
#tp.feed(fd.read())
tp.feed(data)
print "Title is:", tp.gettitle()

