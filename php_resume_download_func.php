<?php
/**
 * @author levinxo
 * @date 2016/02/15
 * @brief php实现的断点续传下载函数
 */


/**
 * @param string path 文件路径
 * @return void
 */
function resume_download($path){

    $file = file_get_contents($path);
    if (strlen($file) <= 0){
        exit('no file');
    }
    $file_length = strlen($file);

    header("Content-Type: application/zip");
    header("Content-Disposition: filename=abc.zip");
    //重要，声明服务器可以接受按字节获取该资源某部分的请求
    header("Accept-Ranges: bytes");

    /**
     * 如果客户端请求的头部中带了Range字段，说明是请求资源的一部分或多部分
     */
    if (isset($_SERVER['HTTP_RANGE'])){

        list(, $range) = explode("=", $_SERVER['HTTP_RANGE']);
        $range = trim($range);

        if (is_numeric($range) && 0 > $range){
            //类似-500的情况（取最后几个字节）
            $client_start = $file_length - abs($range);
            $client_end   = $file_length - 1;
            $client_length = abs($range);
        } elseif (false === strpos($range, ',')){
            //类似0-499的情况（从start到end）
            list($client_start, $client_end) = explode('-', $range);
            //类似0-的情况（从start一直取到末尾）
            if ($client_end == ''){
                $client_end = $file_length - 1;
            }
            $client_length = $client_end - $client_start + 1;
        } else {
            //类似0-0,-1以及500-700,601-999的情况（取多个部分），很少见，暂时不处理了
        }

        if ($client_length <= 0
            || $client_length > $file_length
            || $client_start > $client_end
        ){
            //告诉客户端，range非法了并给出正确的长度
            header('HTTP/1.1 416 Requested Range Not Satisfiable');
            header(sprintf("Content-Range: bytes */%d", $file_length));
        }

        header("HTTP/1.1 206 Partial Content");
        header("Content-Length: $client_length");
        header(sprintf("Content-Range: bytes %d-%d/%d", $client_start, $client_end, $file_length));

        echo substr($file, $client_start, $client_length);
    } else {

        header("Content-Length: ".$file_length);
        echo $file;
    }
}







