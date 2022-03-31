class Solution
{
public:
    vector<string> Permutation(string str)
    {
        std::vector<string> result;

        // corner case: Empty
        if (!str.empty()) {
            m_Permutation(str, 0, result);
            // 此时得到的result中排列并不是字典顺序，可以单独再排下序
            sort(result.begin(), result.end());
        }
        return result;
    }

    void m_Permutation(string str, int index, vector<string>& result)
    {
        // 注意点
        // 1：递归出口，string扫描完了
        // 2：何时加入结果：在递归出口前，因为当前string已经遍历完了，所以当前string应该加入结果
        // 2：如何解决重复: 在vector emplace时自行判断
        // 4：字典序：递归前排序，或递归后对结果排序
        auto size = str.size();
        if (index == size - 1) {
            if (std::find(result.begin(), result.end(), str) == result.end())
                result.emplace_back(str);
            return;
        }

        //下标要从index开始，不能漏掉当前字母开头的排列情况
        for (auto i = index; i < size; i++) {
            std::swap(str[i], str[index]);  // 拿abb构想一下，先交换，后递归
            m_Permutation(str, index + 1, result);
        }
    }
};