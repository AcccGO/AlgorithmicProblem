class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return bool布尔型
     */
    bool isNumeric(string str)
    {
        auto has_dot            = false;
        auto has_e              = false;
        auto has_left_operator  = false;
        auto has_right_operator = false;
        auto e_index            = str.size();
        auto left_operator      = -2;

        auto index = 0;
        for (auto const& i : str) {
            if (i == '.') {
                // 已经有dot；dot在E后面；str只有一个dot
                if (has_dot || index > e_index || index == str.size() - 1) return 0;
                has_dot = true;
            } else if (i == 'E' || i == 'e') {
                // E在开头；E在结尾；已经有E；E前面只有一个符号
                if (index == 0 || index == str.size() - 1 || has_e || index == left_operator + 1) return false;
                has_e   = true;
                e_index = index;
            } else if (i == '+' || i == '-') {
                // 如果是E左边的符号
                if (index < e_index) {
                    // 左边已经有符号；符号不在左边开头；str只有这一个符号
                    if (has_left_operator || index != 0 || (index == 0 && str.size() == 1)) return false;
                    has_left_operator = true;
                    left_operator     = index;
                } else {
                    // 右边已经有符号；符号不在E紧邻右侧；str只有这一个E
                    if (has_right_operator || index != e_index + 1 || index == str.size() - 1) return false;
                    has_right_operator = true;
                }
            } else if (i < '0' || i > '9') {
                // 其余如果不是数字符号
                return false;
            }

            index++;
        }

        return true;
    }
};