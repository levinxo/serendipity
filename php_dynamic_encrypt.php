<?php

function code_generate($str='', $encrypt=true){
	$const_key = 'type private code here.';
	$random_key = $encrypt? hash_hmac('sha1', microtime(true), $const_key): substr($str, 0, 40);

	$str = $encrypt? $str: base64_decode(substr($str, 40));
	$str_len = strlen($str);
	$code = '';
	for ($i=0; $i<$str_len; $i++){
		$code .= chr(ord($str{$i}) ^ ord($random_key{$i%40}));
	}
	$code = $encrypt? $random_key.base64_encode($code): $code;
	return $code;
}


echo $a = code_generate('测试測試abc123');
echo "\n";
echo code_generate($a, false);
