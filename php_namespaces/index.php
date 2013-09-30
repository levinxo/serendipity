<?php

namespace index;

const i = 'index';

function f(){
    return __FUNCTION__;
}

class c {

    public static function f(){
        return __METHOD__;
    }

}

include('./file1.php');
include('./file2.php');

use lib\lib1;
use lib\lib2 as lib2;

echo i;echo '<br>';
echo f();echo '<br>';
echo c::f();echo '<br>';

echo \lib\lib1\i;echo '<br>';
echo \lib\lib1\f();echo '<br>';
echo \lib\lib1\c::f();echo '<br>';

echo lib2\i;echo '<br>';
echo lib2\f();echo '<br>';
echo lib2\c::f();echo '<br>';

