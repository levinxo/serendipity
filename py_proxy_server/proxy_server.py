#!/bin/env python
# -*- coding: UTF-8 -*-

import socket, select, threading

__ver__ = '1.0 Alpha'
__author__ = 'jiangjiajun'
VERSION = 'Tiny Python Proxy/' + __ver__
HOST = '0.0.0.0'
PORT = 8008
RECVBUFFER = 8000
HTTPVER = 'HTTP/1.1'

class Gear():
    def __init__(self, accept):
        self.clientsock, self.clientaddr = accept
        self.clientsend = ''

        self.method, self.path, self.protocol = self.getClientHeader()
        if self.method == 'CONNECT':
            self.CONNECT_method()
        elif self.method in ('GET', 'POST', 'PUT', 'DELETE', 'HEAD', 'OPTIONS', 'TRACE'):
            self.other_method()

        self.clientsock.close()
        self.remote.close()

    def getClientHeader(self):
        while True:
            self.clientsend += self.clientsock.recv(RECVBUFFER)
            gap = self.clientsend.find('\n')
            if gap != -1:
                break
        data = self.clientsend[:gap].split()
        self.clientsend = self.clientsend[gap+1:]
        return data

    def CONNECT_method(self):
        self.connectRemote()
        self.clientsock.send('%s 200 Connection Established\r\nProxy-Agent: %s\r\n\r\n'%(HTTPVER, VERSION))
        self.handOut()

    def other_method(self):
        self.path = self.path[7:]
        gap = self.path.find('/')
        path = self.path[gap:]
        self.path = self.path[:gap]
        self.connectRemote()
        self.remote.send('%s %s %s\r\n'%(self.method, path, self.protocol) + self.clientsend)
        self.handOut()

    def connectRemote(self):
        gap = self.path.find(':')
        if gap != -1:
            host = self.path[:gap]
            port = int(self.path[gap+1:])
        else:
            host = self.path
            port = 80

        soctype, _, _, _, socaddr = socket.getaddrinfo(host, port)[0]
        self.remote = socket.socket(soctype, socket.SOCK_STREAM)
        self.remote.connect(socaddr)

    def handOut(self):
        count = 0
        while True:
            count += 1
            recv, _, error = select.select([self.clientsock, self.remote], [], [], 3)
            if error:
                break
            if recv:
                for r in recv:
                    data = r.recv(RECVBUFFER)
                    if r is self.clientsock:
                        target = self.remote
                    else:
                        target = self.clientsock
                    if data:
                        target.send(data)
                        count = 0
            if count == 10:
                break

class Engine():

    def run(self):
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            self.socket.bind((HOST, PORT))
        except:
            print 'socket.bind() error.'
            raise SystemExit
        self.socket.listen(5)
        while True:
            gear = threading.Thread(target=Gear, args=[self.socket.accept()])
            gear.start()

if __name__ == '__main__':
    engine = Engine()
    engine.run()
