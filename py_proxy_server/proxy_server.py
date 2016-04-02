#!/bin/env python
# -*- coding: UTF-8 -*-

import socket, select, threading

__ver__      = '1.0 Alpha'
__author__   = 'jiangjiajun'

AGENT        = 'Tiny Python Proxy/' + __ver__
HTTP_VER     = 'HTTP/1.1'
SERVER_HOST  = '0.0.0.0'
SERVER_PORT  = 8008
RECV_BUFFER  = 8000


class ProxyGear(object):


    '''客户端请求的远程地址'''
    @property
    def strCliPath(self):
        return self._strCliPath

    @strCliPath.setter
    def strCliPath(self, value):
        self._strCliPath = value

    '''远程服务器sock'''
    @property
    def objRemoteSock(self):
        return self._objRemoteSock

    @objRemoteSock.setter
    def objRemoteSock(self, value):
        self._objRemoteSock = value

    '''客户端sock'''
    @property
    def objCliSock(self):
        return self._objCliSock

    @objCliSock.setter
    def objCliSock(self, value):
        self._objCliSock = value

    '''http协议版本'''
    @property
    def strCliProtocol(self):
        return self._strCliProtocol

    @strCliProtocol.setter
    def strCliProtocol(self, value):
        self._strCliProtocol = value

    '''请求方法'''
    @property
    def strCliMethod(self):
        return self._strCliMethod

    @strCliMethod.setter
    def strCliMethod(self, value):
        self._strCliMethod = value

    '''客户端请求的头部'''
    @property
    def strCliSend(self):
        return self._strCliSend

    @strCliSend.setter
    def strCliSend(self, value):
        self._strCliSend = value


    def __init__(self, accept):
        self.objCliSock, clientAddr = accept
        print "Connection from %s" % (clientAddr[0])

        '''请求方法，路径，协议版本'''
        self.strCliMethod, self.strCliPath, self.strCliProtocol = self.parseClientHeader()

        '''和远程服务器建立连接，维持客户端和远程服务器的数据交互'''
        if self.strCliMethod == 'CONNECT':
            self.connectMethod()
        elif self.strCliMethod in ('GET', 'POST', 'PUT', 'DELETE', 'HEAD', 'OPTIONS', 'TRACE'):
            self.generalMethod()

        '''关闭连接'''
        self.objCliSock.close()
        self.objRemoteSock.close()


    '''解析客户端请求头部'''
    def parseClientHeader(self):
        data = ''
        while True:
            data += self.objCliSock.recv(RECV_BUFFER)
            gap = data.find('\n')
            if gap != -1:
                break

        self.strCliSend = data[gap+1:]

        '''请求方法，路径，协议'''
        return data[:gap].split()


    '''CONNECT方法'''
    def connectMethod(self):
        self.connectRemote()
        self.objCliSock.send('%s 200 Connection Established\r\nProxy-Agent: %s\r\n\r\n' % (HTTP_VER, AGENT))
        self.interact()


    '''除CONNECT外其它的方法'''
    def generalMethod(self):
        path = self.strCliPath[7:]
        gap = path.find('/')
        self.strCliPath = path[:gap]
        uri = path[gap:]

        self.connectRemote()
        self.objRemoteSock.send('%s %s %s\r\n' % (self.strCliMethod, uri, self.strCliProtocol) + self.strCliSend)
        self.interact()


    '''和远程服务器建立连接'''
    def connectRemote(self):
        gap = self.strCliPath.find(':')
        if gap != -1:
            host = self.strCliPath[:gap]
            port = int(self.strCliPath[gap+1:])
        else:
            host = self.strCliPath
            port = 80

        soctype, _, _, _, socaddr = socket.getaddrinfo(host, port)[0]
        self.objRemoteSock = socket.socket(soctype, socket.SOCK_STREAM)
        self.objRemoteSock.connect(socaddr)


    '''维持客户端和远程服务器的数据交互'''
    def interact(self):
        count = 0
        while True:
            count += 1
            objRecv, _, error = select.select([self.objCliSock, self.objRemoteSock], [], [], 3)
            if error:
                break
            if objRecv:
                for recv in objRecv:
                    data = recv.recv(RECV_BUFFER)
                    if recv is self.objCliSock:
                        target = self.objRemoteSock
                    else:
                        target = self.objCliSock
                    if data:
                        target.send(data)
                        count = 0
            if count == 10:
                break


class ProxyEngine():


    '''监听端口并开启线程代理请求'''
    def launch(self):
        objSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        try:
            objSocket.bind((SERVER_HOST, SERVER_PORT))
        except Exception as e:
            print e
            raise SystemExit

        objSocket.listen(5)
        while True:
            gear = threading.Thread(target=ProxyGear, args=[objSocket.accept()])
            gear.start()


if __name__ == '__main__':
    engine = ProxyEngine()
    engine.launch()


