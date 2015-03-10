<?php

$a = "\xe3\x81\x8d\xe3\x82\x93\xe3\x81\x86";
$b = 'きんう';

//将16进制转为字符
echo preg_replace_callback('/\\x[0-9a-f]{2}/', function($matches){
    list($digit) = sscanf('0'.substr($matches[0], 1), "%x");
    return pack('C', $digit);
}, $a);

//将字符转为16进制表示
echo '\x'.implode('\x', str_split(bin2hex($b), 2));

