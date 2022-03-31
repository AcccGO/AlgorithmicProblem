class Solution
{
public:
    string ReverseSentence(string str)
    {
        if (str.empty()) return str;

        //   Ugly version
        //   Parse string
        std::vector<string> parsed_string;
        auto start = 0, end = 0;
        int size = str.size();
        while (end < size) {
            if (str[end] == ' ' || end == (size - 1)) {
                auto sub_start = end == (size - 1) ? start + 1 : start;
                parsed_string.emplace_back(str.substr(sub_start, end - start));
                start = end;
            }
            end++;
        }

        // 不然一个单词会输出错误
        if (parsed_string.size() == 1) return str;

        str.clear();
        if (parsed_string.size() > 1) parsed_string.front() = ' ' + parsed_string.front();
        for (auto s : parsed_string) {
            str = s + str;
        }

        return str;
    }
};