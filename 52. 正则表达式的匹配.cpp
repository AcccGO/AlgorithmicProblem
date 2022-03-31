class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern)
    {
        int m = str.size();
        int n = pattern.size();

        // dp[i][j]表示str的前i位和pattern的前j位是否匹配
        //  00存放两个空字符串结果
        //  初始化都为false
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // 特判一方为空的情况
        dp[0][0] = true;
        for (auto j = 2; j < n + 1; j++) {
            if (pattern[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }

        for (auto i = 1; i < m + 1; i++) {
            for (auto j = 1; j < n + 1; j++) {
                auto s_id = i - 1;
                auto p_id = j - 1;
                // 如果第j个元素不是*
                // 那么采用正常的匹配方式，即模式串的第j个元素与字符串的第i个元素一样
                // 或者模式串的第j个元素是‘.’
                // 此时，dp[i][j]=dp[i-1][j-1]
                if (pattern[p_id] != '*') {
                    if (str[s_id] == pattern[p_id] || pattern[p_id] == '.')
                        dp[i][j] = dp[i - 1][j - 1];
                }

                // 如果第j个元素是*，那么分两种情况，有一种情况为true即可
                // 第一种将*前面那个元素视为空串（这时*代表出现0次），那么dp[i][j-2]==true即表示匹配成功
                // 如果s的第i个元素与p的第j-1个元素相等（此时代表的是出现1次），或者p的第j-1个元素是‘.’
                // 此时，dp[i][j] = dp[i][j-2] || dp[i-1][j]
                else {
                    if (str[s_id] == pattern[p_id - 1] || pattern[p_id - 1] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];  // 前面代表出现0次*前字符，后面代表出现1次及以上
                    } else {
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }

        return dp[m][n];
    }
};