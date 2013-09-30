<?php

namespace lib\lib2;

const i = 'lib\lib2';

function f(){
    return __FUNCTION__;
}

class c {

    public static function f(){
        return __METHOD__;
    }

}
