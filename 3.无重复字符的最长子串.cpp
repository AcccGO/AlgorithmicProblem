/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::string temp;
        int max_length = 0;

        for (auto& ss : s) {
            // 话说，可以直接用int find_first_of(char c, int start = 0)函数？
            int index = -1;
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == ss) {
                    index = i;
                    break;
                }
            }

            temp += ss;
            temp = temp.substr(index + 1);

            // 不能放在开头，因为可能下次ss就遍历完了，不会再更新max了
            max_length = max(temp.size(), max_length);
        }

        return max_length;
    }
};
// @lc code=end

// Good solution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
};