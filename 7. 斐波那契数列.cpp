class Solution
{
public:
    int Fibonacci(int n)
    {
        // corner case
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int last_last = 0;
        int last      = 1;
        int current   = 0;

        // 迭代
        // 复杂度O(N)
        for (int i = 2; i <= n; i++) {
            current   = last + last_last;
            last_last = last;
            last      = current;
        }

        return current;
    }
};