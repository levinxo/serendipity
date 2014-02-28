<?php

$params = array(
    'hello' => 'world',
    'a' => 1
);

$soap_client = _soapClient();       //获得soapClient类的实例
$ret = _soapCall($soap_client, 'hello', $params);   //第二个参数为webservice提供方法里其中的一个方法名，第三个往后就是方法所需要的参数，这里传了1个数组

var_dump($ret);     //打印输出

/*-------下面是封装好的函数-------*/

/**
 * 返回soap客户端的实例
 */
function _soapClient(){
    return new SoapClient('http://localhost/soap/server.php?wsdl');
}

/**
 * 向webservice发送信息并获取结果
 */
function _soapCall($soap, $func, $params=array()){
    try {
        return $soap->$func($params);
    }
    catch (SoapFault $e){
        $msg = $e->getMessage();
        _debug("soap-fault: $msg");
        return $msg;
    }
    catch (Exception $e){
        $msg = $e->getMessage();
        _debug("soap-exception: $msg");
        return $msg;
    }
}

function _debug($msg){
    echo $msg;
}
