import socket


c = '''GET / HTTP/1.1\r\nHost: *.*.*.*\r\n\r\n'''
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('127.0.0.1', 80))
sock.send(c)
print sock.recv(9999)
sock.close()
