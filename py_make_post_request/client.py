import socket

post_data = 'post_param1=a&post_param2=b'
request_str = '''POST /serendipity/py_make_post_request/?get_param1=a&get_param2=b HTTP/1.1\r\nHost: *.*.*.*\r\nContent-Length: '''+str(len(post_data))+'''\r\nContent-Type: application/x-www-form-urlencoded\r\n\r\n'''+post_data

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(('127.0.0.1', 80))
sock.send(request_str)
print sock.recv(9999)
sock.close()
