<?php

if (isset($_GET['wsdl'])){      //将wsdl文件输出
    header('Content-Type: application/xml');
    include('./test.wsdl');exit;
}

class Test {
    /**
     * hello..
     * @param array $param
     * @return array
     */
    public function hello($param){
        return $param;
    }
}

$server = new SoapServer('./test.wsdl');        //启动webservice
$server->setClass('Test');                      //给ws加载类，使其能向外部提供方法接口
$server->handle();
