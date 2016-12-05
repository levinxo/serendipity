<?php

/**
 * @brief 对带有权重的数组随机抽取一个元素，返回它的key
 * @return int
 */
function roll($arrWeight){
    $roll       = rand(1, array_sum($arrWeight));
    $tmp_weight = 0;
    $roll_key   = 0;

    foreach ($arrWeight as $k => $v){
        $min = $tmp_weight;
        $tmp_weight += $v;
        $max = $tmp_weight;
        if ($roll > $min && $roll <= $max){
            $roll_key = $k;
            break;
        }
    }

    return $roll_key;
}

//test
$arr = array(
    10,
    90,
);

foreach (range(0,9) as $v){
    $key = roll($arr);
    var_dump($key);
}

