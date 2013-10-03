/*
 * jquery waterfall plugin
 * @author xlevin.com
 * @email levinxo@gmail.com
 * */

+function($){ "use strict";
    $.fn.waterfall = $.prototype.waterfall = function(options){
        //配置
        var _config = {
            item: null      //要加入瀑布流的item
            ,resize: false  //是否将已加入瀑布流的item进行重新排列
            ,con_class: 'wf-row' //将item包起来的外框class
            ,margin_right: 10   //右margin
            ,margin_bottom: 15  //下margin
        };
        options = $.extend(_config, options);

        return $(this).each(function(c){
            var outer_con = this;

            if (!options.resize){
                var con = document.createElement('div');    //外框
                con.className = options.con_class;
                con.id = options.con_class+'-'+(c+1)+'-'+($(outer_con).children('.'+options.con_class).length+1);
                $(con).append(options.item);
                $(outer_con).append(con);
            }

            //初始化变量
            var $items = options.resize? $(outer_con).children('.'+options.con_class).eq(0).children('div'): $(con).children('div'),
                item_width = $items.eq(0).outerWidth() + options.margin_right,
                column = Math.floor($(outer_con).outerWidth()/item_width);

            //尝试去掉最右边的margin看是否能增加一列
            if (item_width*(column+1)-options.margin_right<=$(outer_con).outerWidth()){
                column+=1;
            }
            if (column < 1){
                column = 1;
            }

            var item_arrange = function(_con, _$items){
                var tmp_height = $(outer_con).data('wf_item_height'),
                    items_pos = [];
                if (typeof tmp_height == 'undefined'){
                    for (var i=0; i<column; i++){
                        items_pos.push([i*item_width, 0]);
                    }
                } else {
                    for (var i=0; i<column; i++){
                        items_pos.push([i*item_width, tmp_height[i]]);
                    }
                }

                _$items.each(function(){
                    $(this).hover(function(){
                        $(this).addClass('active');
                    }, function(){
                        $(this).removeClass('active');
                    });
                    var _tmp = 0, item_height = $(this).outerHeight() + options.margin_bottom;
                    for (var i=0; i<column; i++){
                        if(items_pos[i][1] < items_pos[_tmp][1]){
                            //保存高度最小那列的序号，稍后将item移到此缺口
                            _tmp = i;
                        }
                    }
                    this.style.left = items_pos[_tmp][0]+'px';
                    this.style.top = items_pos[_tmp][1]+'px';
                    //插入后，增加此列的top值
                    items_pos[_tmp][1] += item_height;
                });

                var _tmp_height = [];   //重新对高度进行赋值
                for (var i=0; i<items_pos.length; i++){
                    _tmp_height.push(items_pos[i][1]);    //获取每列的高度
                }

                $(outer_con).data('wf_item_height', _tmp_height); //存储元素的高度位置值
                //瀑布流产生的最高高度
                var con_height = eval('Math.max('+_tmp_height.join(',')+')');

                $(outer_con).children('.'+options.con_class).each(function(i){
                    if (this.id == _con.id){
                        return false;
                    }
                    con_height -= $(this).outerHeight();
                });

                $('#'+_con.id).css('height', con_height);
            };

            if (options.resize){
                $(outer_con).removeData('wf_item_height');
                $(outer_con).children('.'+options.con_class).each(function(){
                    item_arrange(this, $(this).children('div'));
                });
            } else {
                item_arrange(con, $items);
            }
        });
    }
}(window.jQuery);
