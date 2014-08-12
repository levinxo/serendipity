//detect mouse moving position when mouse down
(function($){"use strict";
    $.fn.getMousePos = $.prototype.getMousePos = function(options){
        //init config
        var options = options || {}, _config = {
            time_gap: 500      //ms
            ,callback: null     //callback function
        };
        options = $.extend(_config, options);

        this.each(function(){
            var ele = this, t, m_x, m_y;

            $(ele).data('mouse_move_evt', function(e){
                m_x = e.clientX;
                m_y = e.clientY;
            });

            $(ele).mousedown(function(e){
                if (e.button != 0){return false;}

                var result = [], ele_x = $(ele).offset()['left'], ele_y = $(ele).offset()['top'];
                m_x = e.clientX;
                m_y = e.clientY;

                $(ele).bind('mousemove', $(ele).data('mouse_move_evt'));
                var loop_send = function(){
                    result.push({x: m_x, y: m_y});
                };
                loop_send();
                t = setInterval(loop_send, options.time_gap);

                $(ele).data('mouse_up_evt', function(){
                    $(ele).unbind('mousemove', $(ele).data('mouse_move_evt'));
                    clearInterval(t);
                    $(window).unbind('mouseup', $(ele).data('mouse_up_evt'));

                    if (typeof options.callback == 'function'){
                        result = result.map(function(a){
                            return {
                                x: Math.round(a.x - ele_x),
                                y: Math.round(a.y - ele_y)
                            };
                        });
                        options.callback(result);
                    }
                });
                $(window).bind('mouseup', $(ele).data('mouse_up_evt'));
            });
        });
    };
})(window.jQuery);
