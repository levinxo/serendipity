<?php

/**
 * 此脚本用于将远程或本地图片转为base64码
 * @author xlevin.com
 * @date 2013-11-06 22:32:00
 */

$img = imagecreatefrompng('https://www.gravatar.com/avatar/1dd48e8094f0475d80b8f3d3b9f9dfca?s=128&d=identicon&r=PG');
ob_start();
imagepng($img);
$img_bin = ob_get_clean();
$img_base64 = base64_encode($img_bin);

?>


<img src="data:image/png;base64,<?php echo $img_base64; ?>">


