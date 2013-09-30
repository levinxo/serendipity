<?php

namespace lib\lib1;

const i = 'lib\lib1';

function f(){
    return __FUNCTION__;
}

class c {

    public static function f(){
        return __METHOD__;
    }

}
