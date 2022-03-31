class Solution
{
public:
    int GetNumberOfK(vector<int> data, int k)
    {
        return m_GetNumberOfK(data, k, 0, data.size() - 1);
    }

    int m_GetNumberOfK(vector<int>& data, int k, int left, int right)
    {
        if (data.empty() || left > right || k < data[left] || k > data[right]) return 0;

        if (left == right && data[left] == k) return 1;

        int half_size = (left + right) / 2;
        return m_GetNumberOfK(data, k, left, half_size) + m_GetNumberOfK(data, k, half_size + 1, right);
    }
};