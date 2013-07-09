# -*- coding: utf-8 -*-

import re
import os

def main():
	log_dir = './log'
	last_file = 'access_20130531.log'
	reg = re.compile('3gplay_imsi=(\d+);')
	old = []
	new = []

	for i in os.listdir(log_dir):
		if i == last_file:
			continue
		print '开始处理：', i
		path = os.path.join(log_dir, i)
		f = file(path, 'r')
		data = f.read()
		f.close()

		match = reg.findall(data)
		for j in match:
			if j in old:
				continue
			old.append(j)

	print '开始计算今日新增uv...'
	f = file(os.path.join(log_dir, last_file))
	data = f.read()
	f.close()
	match = reg.findall(data)

	for i in match:
		if i in old or i in new:
			continue
		new.append(i)

	print '今日新增uv：', len(new)
	print ''

if __name__ == '__main__':
	main()
	w = raw_input('Press <Enter> to exit')
