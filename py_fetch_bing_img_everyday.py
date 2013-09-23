#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re, socket, select


def _req(url):
    r = '''GET / HTTP/1.1\r\nHost: '''+url+'''\r\n\r\n'''
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((url, 80))
    s.send(r)
    data = ''
    e_count = 0
    while True:
        e_count += 1
        recvs, _, error = select.select([s], [], [], 0.1)   #can down to 0.03, but lose data sometimes
        if error:
            break
        if recvs:
            print 'start recv..'
            for recv in recvs:
                d = recv.recv(9000)
                if (d):
                    print 'data length: ', len(d)
                    data = data + d
                    e_count = 0
            
        if e_count == 5:
            break
        
        print e_count
        
    return data
    

if __name__ == '__main__':
    data = _req('cn.bing.com')
    print 'total data length: ', len(data)
    
