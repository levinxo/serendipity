#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket, re, threading, time, sys

buffer_pool = []                #store the request return data
tmp_buffer_pool = []            #when buffer_pool is locked it will store the request return data
req_num = 0                     #success request count
req_num_flag = 0                #success request count when equal tmp_store_count it will reset
SOCKET_OPEN_LIMIT = 200         #max socket open
tmp_store_count = 1000          #buffer_pool limit num
is_lock = False                 #is lock buffer_pool

def _make_request():
    r = '''GET /*** HTTP/1.1\r\nHost: *.*.*.*\r\n\r\n'''
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect(('*.*.*.*', 80))
    s.send(r);
    data = s.recv(9999)
    reg = re.compile('src="([^"]+)"')
    m = reg.search(data)
    if m is not None:
        return m.group(1)
    return ''

def _write_file():
    global buffer_pool
    print '----------------------将数据写入文件----------------------'
    f = file('./req.log', 'a')
    f.write('\n'.join(buffer_pool) + '\n')
    f.close()
    buffer_pool = []
    print '----------------------数据写入已完成----------------------'
    time.sleep(5)
    return True

def make_request():
    global req_num, req_num_flag
    while True:
        if len(tmp_buffer_pool) > 0:
            m = tmp_buffer_pool.pop()
        else:
            m = _make_request()
            req_num += 1
            req_num_flag += 1
            print '第', req_num, '次请求完成'
        if (not is_lock):
            buffer_pool.append(m)
        else:
            tmp_buffer_pool.append(m)

        if req_num_flag != 0 and req_num_flag%tmp_store_count == 0:
            write_file()

def write_file():
    is_lock = True
    _write_file()
    is_lock = False

def main():
    for i in range(SOCKET_OPEN_LIMIT):
        t = threading.Thread(target=make_request)
        t.start()
    return True

if __name__ == '__main__':
    main()
