class Solution
{
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 找规律归纳
        // k = n % (i * 10)
        // count(i) = (n / (i * 10)) * i + (if(k > i * 2 - 1) i else if(k < i) 0 else k - i + 1)

        // corner case
        if (n < 0) return 0;

        // int max_i = std::log10((double)n);
        int sum = 0;
        for (int i = 1; i <= n; i *= 10) {
            int tmp     = 10 * i;
            int k       = n % tmp;
            int count_i = n / tmp * i + std::max(0, std::min(i, k - i + 1));
            sum += count_i;
        }
        return sum;
    }
};