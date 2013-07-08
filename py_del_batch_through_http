# -*- coding: utf-8 -*-


import urllib2
from urllib import urlencode
from cookielib import LWPCookieJar
#from time import strftime, sleep
from getpass import getpass
from re import compile

login_url = 'http://url/auth/login'
user_index_url = 'http://url/activity/actuser/index?queryType=&queryValue=&offset='	#以30递增，从0始
user_del_url = 'http://url/activity/actuser/deleteactUser?id='
#imusic read game dm tv store
base_index_url = 'http://url/base/musicbase?type=store&offset='
base_del_url = 'http://url/base/musicbase/deletebase?type=store&id='
end_offset = 61

class curl:

	def __init__(self):
		self.logindata = {}
		self.username = ''
		self.password = ''

		#在http交互中即时更新cookie
		self.cookiejar = LWPCookieJar()
		cookiesupport = urllib2.HTTPCookieProcessor(self.cookiejar)
		opener = urllib2.build_opener(cookiesupport, urllib2.HTTPHandler)
		urllib2.install_opener(opener)



	#登录动作
	def login(self):

		self.logindata['username'] = self.username   #用户名
		self.logindata['password'] = self.password   #用户密码


		try:
			req = urllib2.Request(login_url, urlencode(self.logindata))
			data = urllib2.urlopen(req)
			text = data.read()#.decode('utf-8')#.encode('gb2312') #将utf-8解码再编码为gb2312
			return text
		except:
			pass

	def users_del(self):
		#for range(0, 3391, 30)
		for i in range(0, end_offset, 30):
			try:
				#print user_index_url+str(end_offset-i-1)
				req = urllib2.Request(user_index_url+str(end_offset-i-1))
				data = urllib2.urlopen(req)
				text = data.read()#.decode('utf-8')

				reg = compile('onclick="deleteactUser\((\d+),this\);"')
				match = reg.findall(text)
				for j in match:
					req = urllib2.Request(user_del_url+j)
					urllib2.urlopen(req)
				print '已删除第', (end_offset-i-1)/30+1, '页用户'
			except:
				pass



	def base_del(self):
		for i in range(0, end_offset, 30):
			try:
				req = urllib2.Request(base_index_url+str(end_offset-i-1))
				data = urllib2.urlopen(req)
				text = data.read()

				reg = compile('onclick="deletebase\((\d+),this\);"')
				match = reg.findall(text)
				if end_offset-i-1 == 0:
					break
				for j in match:
					req = urllib2.Request(base_del_url+j)
					urllib2.urlopen(req)
				print '已删除第', (end_offset-i-1)/30+1, '页资源'
			except:
				pass


def main():

	while ch.username == '':
		ch.username = raw_input('输入登录的用户名：\n')
	while len(ch.password) < 3:
		print '\r密码：',
		ch.password = getpass('\n')
	print '\r'

	print '登陆中...'
	text = ch.login()

	if 'user/person' in text:
		act = raw_input('登录成功，请选择操作：\n')
		if act == '1':
			pass
			#ch.users_del()
		if act == '2':
			pass
			#ch.base_del()


	else:
		print '登录失败，请重新登录...'
		ch.username = ''
		ch.password = ''
		main()

	return True

if __name__ == '__main__':
	ch = curl()
	main()
