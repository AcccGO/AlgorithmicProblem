class Solution
{
public:
    vector<int> multiply(const vector<int>& A)
    {
        int a_size = A.size();
        std::vector<int> result(a_size, 1);

        // 左下三角
        for (auto i = 1; i < a_size; i++) {
            result[i] = result[i - 1] * A[i - 1];
        }

        // 右上三角
        auto tmp = 1;
        for (auto i = a_size - 2; i >= 0; i--) {
            tmp = tmp * A[i + 1];
            result[i] *= tmp;
        }

        return result;
    }
};