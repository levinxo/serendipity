<?php

/**
 * 从1加到1000的和
 */
function c($a){
    return $a > 1000? 0: $a + c($a+1);
}

echo c(1);
