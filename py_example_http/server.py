import socket

host = ''
port = 8000

y = '''HTTP/1.1 200 OK\r\nContent-Type: text/html;charset=utf-8\r\n\r\n<html>
<h1>hello, world</h1>
</html>'''



s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host, port))
s.listen(5)


while True:
	clientsock, clientaddr = s.accept()
	print ('Got connection from', clientsock.getpeername())
	data = clientsock.recv(4096)
	print data
	clientsock.send(y)
	clientsock.close()
