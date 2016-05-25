<?php

/**
 * @brief 列出文件夹下的所有文件，使用广搜遍历
 * @param string 目录path
 * @return array 所有文件路径列表
 */
function scan_flies($dir){
    $start = 0;
    $end   = 1;
    $dir_queue = array(
        0 => $dir,
    );
    $file_list = array();

    while ($start < $end){
        $top_dir = $dir_queue[$start++];
        if (is_dir($top_dir)){
            $sub_dir_queue = scandir($top_dir);
            foreach ($sub_dir_queue as $tmp_dir){
                if ('.' === $tmp_dir || '..' === $tmp_dir){
                    continue;
                }
                $dir_queue[$end++] = $top_dir.DIRECTORY_SEPARATOR.$tmp_dir;
            }
        } else {
            if (file_exists($top_dir)){
                array_push($file_list, $top_dir);
            }
        }
    }

    return $file_list;
}


