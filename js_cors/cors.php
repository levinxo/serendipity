<?php

//header('Access-Control-Allow-Origin: *');
header('Access-Control-Allow-Origin: http://example.foo');

$r = array(
	'data' => array(),
	'errno' => 0
);

echo json_encode($r);

