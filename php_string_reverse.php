<?php

$a = 'abcdefg';
$a = implode('', array_reverse(str_split($a)));
echo $a;
//gfedcba

