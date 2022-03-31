class Solution
{
public:
    int StrToInt(string str)
    {
        // corner case
        if (str.empty()) return 0;

        int signed_value = 1;
        if (str.front() == '+' || str.front() == '-') {
            signed_value = str.front() == '-' ? -1 : 1;
            str          = str.substr(1);
        }

        // 判断字符的ASCII范围（数字的范围为48~57）
        auto final_value = 0;
        for (auto s : str) {
            auto tmp = (int)s;
            if (tmp < 48 || tmp > 57) return 0;
            final_value = final_value * 10 + tmp - 48;
        }

        return signed_value * final_value;
    }
};