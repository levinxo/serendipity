/**
 * @author www.bicky.me
 * @date 2015-01-22
 * @brief 自动切换代理脚本
 * */

function FindProxyForURL(url, host){
    //被墙的host名单
    var gfw = [
        //google
        '*google.*'
        ,'*gstatic.*'
        ,'*googleusercontent.*'
        ,'*google-analytics.*'
        ,'*appspot.*'
        ,'*googletagmanager.*'
        ,'*googleapis.*'
        ,'*googlecode.*'
        ,'*googlesource.*'
        ,'*blogspot.*'
        ,'*blogger.*'
        ,'*golang.*'
        ,'*chrome.*'
        ,'*gmail.*'
        ,'*chromium.*'
        ,'*googlehosted.*'
        ,'*android.*'
        ,'*googlelabs.*'
        ,'*goo.gl*'
        ,'*googlemail.*'
        //youtube
        ,'*youtube.*'
        ,'*ytimg.*'
        ,'*ggpht.*'
        ,'*googlevideo.*'
        ,'*youtube-nocookie.*'
        //github
        ,'*github.*'
        ,'*githubusercontent.*'
        ,'*githubapp.*'
        ,'*ghconduit.*'
        //wikipedia
        ,'*wikipedia.*'
        ,'*wikimedia.*'
        //twitter
        ,'*twitter.*'
        ,'*twimg.*'
        //facebook
        ,'*facebook.*'
        ,'*akamaihd.*'
        ,'*fbcdn.*'
        ,'*fbsbx.*'
        ,'*giphy.*'
        //amazon
        ,'*amazonaws.*'
        //adobe
        ,'*adobe.*'
        //wordpress
        ,'*wordpress.*'
        ,'*wp.*'
        ,'*kissmetrics.*'
        //gravatar
        ,'*gravatar.*'
        //flickr
        ,'*flickr.*'
        ,'*yimg.*'
    ];
    //白名单，不需要代理
    var whitelist = [
        'localhost'
        ,'127.0.0.1'
    ];

    for (var i in whitelist){
        if (shExpMatch(host, whitelist[i])){
            return 'DIRECT';
        }
    }
    for (var i in gfw){
        if (shExpMatch(host, gfw[i])){
            return 'PROXY 127.0.0.1:8711';
        }
    }
    //其它，不代理
    return 'DIRECT';
}
