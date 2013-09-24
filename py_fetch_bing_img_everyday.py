#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re, socket, select, time, urlparse


def _req(url):
    url_arr = urlparse.urlparse(url)
    r = 'GET '+(url_arr[2] if url_arr[2] != '' else '/')+' HTTP/1.1\r\nHost: '+url_arr[1]+'\r\n\r\n'
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((url_arr[1], 80))
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
        
    s.close()
    return data
    

if __name__ == '__main__':
    while True:
        data = _req('http://cn.bing.com')
        if len(data) > 0:
            break
    
    reg = re.compile("g_img=\{url:'([^']+)'")
    m = reg.search(data)
    if m is not None:
        print m.group(1)
        while True:
            img_data = _req(m.group(1))
            if len(img_data) > 0:
                break
        f = open(time.strftime('%Y-%m-%d')+'.'+m.group(1).split('.')[-1], 'wb')
        img_arr = img_data.split('\r\n\r\n')
        img_arr.pop(0)
        img_data = ''.join(img_arr)
        f.write(img_data)
        f.close()
        print 'fetch img success.'
        
    else:
        print 'img not found.'
    
