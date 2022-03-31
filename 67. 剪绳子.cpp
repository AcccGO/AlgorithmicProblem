class Solution
{
public:
    int cutRope(int number)
    {
        std::vector<int> result(number + 1, 0);

        // 初始条件
        // result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= number; i++) {
            result[i] = i;
            for (int j = 1; j <= i / 2; j++) {
                result[i] = std::max(result[i - j] * result[j], result[i]);  // 转移方程
            }
        }

        return result[number];
    }
};