/**
 * @brief 时钟类
 * @date 2016/08/07
 */

class Clock {

    public:

        /**
         * @brief 构造函数
         */
        Clock();

        /**
         * @brief 设置小时
         */
        void setH(int h);

        /**
         * @brief 设置分钟
         */
        void setM(int m);

        /**
         * @brief 设置秒数
         */
        void setS(int s);

        /**
         * @brief 格式化时间
         */
        void fmtClock(char *str);

        /**
         * @brief 打印时间字符串
         */
        void display();


    private:

        /**
         * 小时数最小长度
         */
        const static int HOUR_MAX_LEN = 2;

        /**
         * 分钟数最小长度
         */
        const static int MIN_MAX_LEN = 2;

        /**
         * 秒数最小长度
         */
        const static int SEC_MAX_LEN = 2;

        /**
         * 时
         */
        int _h;

        /**
         * 分
         */
        int _m;

        /**
         * 秒
         */
        int _s;

};

