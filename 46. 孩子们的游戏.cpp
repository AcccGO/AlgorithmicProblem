class Solution
{
public:
    int LastRemaining_Solution(int n, int m)
    {
        if (n == 0 || m == 0) return -1;

        std::vector<int> g(n, 1);
        int last_index = 0;

        for (int i = 0; i < n - 1; i++) {
            int tmp = last_index;
            for (int j = 0; j < m;)
                if (g[(tmp++) % n] >= 0) j++;
            g[(tmp - 1) % n] = -1;
            last_index       = tmp % n;
        }

        for (int i = 0; i < n; i++)
            if (g[i] >= 0) return i;

        return -1;
    }
};