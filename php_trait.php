<?php
/**
 * @brief
 * php trait特性，将重复的方法拆分到trait集合里，并通过use引入
 *
 * @author jiangjiajun
 * @date 2016/09/24
 */


trait Gas {


    /**
     * 油箱容积
     */
    protected $capacity = 0;


    /**
     * @brief 获取油箱容积
     */
    public function getCapacity(){
        return $this->capacity;
    }


    /**
     * @brief 设置油箱容积
     */
    public function setCapacity($capacity){
        $this->capacity = $capacity;
    }


}


class Car {


    /**
     * 品牌
     */
    protected $brand;


    public function __construct($brand){
        $this->brand = $brand;
    }


    public function getBrand(){
        return $this->brand;
    }

}


class Suv extends Car {


    /**
     * 使用油箱类方法
     */
    use Gas;


    public function __construct($brand){
        parent::__construct($brand);
    }


    public function intro(){
        $brand = $this->getBrand();
        echo "this car brand is $brand\n";

        $this->setCapacity(60);
        $capacity = $this->getCapacity();
        echo "gas capacity is $capacity\n";
    }

}

$objSuv = new Suv('Peugeot');
$objSuv->intro();

