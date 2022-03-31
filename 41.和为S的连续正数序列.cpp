class Solution
{
public:
    vector<vector<int>> FindContinuousSequence(int sum)
    {
        vector<vector<int>> result;
        if (sum <= 2) return result;

        int i      = 1;
        int j      = 2;
        int border = (sum + 1) / 2;  // 注意边界

        // 连续数列，不能是单个数字
        // i >= border以后， i + j 肯定大于等于sum了，假设至少两个数字的情况下
        while (i < j && i < border) {
            int tmp_sum = (i + j) * (j - i + 1) / 2;
            if (tmp_sum < sum)
                j++;
            else if (tmp_sum > sum)
                i++;
            else {
                std::vector<int> q;
                q.reserve(j - i + 1);
                int k = i;
                while (k <= j)
                    q.emplace_back(k++);
                result.emplace_back(q);

                i++;
            }
        }

        return result;
    }
};