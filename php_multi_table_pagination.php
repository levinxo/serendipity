<?php
/*
 * PHP多表查询分页算法
 * */

$offset = empty($_GET['offset'])? 0: $_GET['offset'];   //偏移量
$limit = empty($_GET['limit'])? 20: $_GET['limit'];     //结果集数量

$table_name_list = array(   //表的名字集合
    'table1' => array()
    ,'table2' => array()
    ,'table3' => array()
);

function GenPagination(){
    global $offset;
    global $limit;
    global $table_name_list;

    $count = 0;
    foreach ($table_name_list as $k => $v){
        $count += $table_name_list[$k]['count'] = getTableRowCount($k); //获取当前表的记录总数
        $table_name_list[$k]['total_count'] = $count;       //total_count用于标示当前表和之前遍历的表记录总数
    }

    $cursor = $offset;  //当前偏移的位置
    $rest = $limit;     //还剩多少数量的记录需要取
    $res_lists = array();
    foreach ($table_name_list as $k => $v){
        if ($v['count'] == 0){
            continue;
        }
        if ($cursor < $v['total_count']){  //若偏移的位置小于当前表和之前表记录总数之和，说明有记录可以取出来
            $gain = $v['total_count'] - $cursor;    //当前表从偏移位置开始能取$gain条记录
            $start = $v['count'] - $gain;   //当前表的总记录数减去$gain表示当前表取记录时的偏移开始位置
            if ($gain > $rest){    //若能获取的记录数大于需要取的记录数，则让$gain变为$rest的值
                $gain = $rest;
            }
            $res_list = getTableRows($k, $start, $gain);    //从表中获取对应位置的记录行数据
            $res_lists = array_merge($res_lists, $res_list);    //将获取到的记录行数据和之前的合并
            $rest -= $gain; //需要获取的记录数降低
            $cursor += $gain;   //偏移位置往后移动
            if ($rest == 0){   //若需要获取的记录数量为0，则完成任务，退出循环
                break;
            }
        }
    }
    return $res_lists;
}

//获取当前表的记录总数
function getTableRowCount($table){
    $count = 0;
    switch ($table){
        case 'table1':
            $count = 17;
            break;
        case 'table2':
            $count = 2;
            break;
        case 'table3':
            $count = 2;
    }
    return $count;
}

//从表中获取对应位置的记录行数据
function getTableRows($table, $offset, $limit){
    $tmp_data = array();
    switch ($table){
        case 'table1':
            $tmp_data = range(1, 17);
            break;
        case 'table2':
            $tmp_data = range(18, 19);
            break;
        case 'table3':
            $tmp_data = range(20, 21);
    }
    $tmp_data = array_splice($tmp_data, $offset, $limit);
    return $tmp_data;
}

print_r(GenPagination());