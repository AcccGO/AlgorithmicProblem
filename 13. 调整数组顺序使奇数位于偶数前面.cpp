class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        // 方法1： 以空间换时间
        auto odd_count = 0;
        for (auto &i : array)
            if ((i & 1) == 1) odd_count++;

        auto odd_index  = 0;
        auto even_index = odd_count;
        std::vector<int> new_array(array);

        for (auto &i : new_array) {
            if ((i & 1) == 0)
                array[even_index++] = i;
            else
                array[odd_index++] = i;
        }

        // 方法2： 直接使用STL函数
        // true 在前
        std::stable_partition(array.begin(), array.end(), [](int i) {
            return (i & 1) == 1;
        });

        // 方法3： 借鉴保持稳定性的排序思路
        // O(N*N)
        auto odd_index = 0;
        auto size      = array.size();
        for (auto i = 0; i < size; i++) {
            if ((array[i] & 1) == 1) {
                for (auto j = i; j > odd_index; j--) {
                    swap(array[j], array[j - 1]);
                }
                odd_index++;
            }
        }
    }
};