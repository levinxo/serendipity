var array_distinct = function(array, del){
    var del = del || '';
    var _self = array.concat();
    var _tmp = array.concat().sort();
    _tmp.sort(function(a, b){
        if (a == b){
            _self.splice(_self.indexOf(a), 1);
        }
    });
    for (var i in _self){
        if (_self[i] == del){
            _self.splice(i, 1);
        }
    }
    return _self;
}
