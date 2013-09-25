#!/usr/bin/env python
# -*- coding: utf-8 -*-

import re, socket, select, time, urlparse, os


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
    if data == '':
        data = _req(url)
    return data
    

if __name__ == '__main__':
    data = _req('http://cn.bing.com')
    
    reg = re.compile("g_img=\{url:'([^']+)'")
    m = reg.search(data)
    if m is not None:
        print 'img url: ', m.group(1)
        
        img_data = _req(m.group(1))
        if not os.path.isdir('./images'):
            os.mkdir('./images')
        f = open('./images/'+time.strftime('%Y-%m-%d')+'.'+m.group(1).split('.')[-1], 'wb')
        img_arr = img_data.split('\r\n\r\n')
        img_arr.pop(0)
        f.write(''.join(img_arr))
        f.close()
        print 'fetch img success.'
        e = raw_input('Press Enter to exit..')
        
    else:
        print 'img not found.'
    
