class Solution
{
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        //         算法时间复杂度O（n）
        //         用total记录累计值，maxSum记录和最大
        //         基于思想：对于一个数A，若是A的左边累计数非负，那么加上A能使得值不小于A，认为累计值对
        //                   整体和是有贡献的。如果前几项累计值负数，则认为有害于总和，total记录当前值。
        //         此时 若和大于maxSum 则用maxSum记录下来

        if (array.empty()) return 0;

        // 不能直接等于0 ，因为总和可能为负
        int result     = array.front();
        int last_value = array.front();
        for (auto i = 1; i < array.size(); i++) {
            // 判断对整个连续子串来说，左半部分已经遍历的部分是否有价值
            if (last_value <= 0)
                last_value = array[i];
            else
                last_value += array[i];
            if (last_value > result) result = last_value;
        }

        return result;
    }
};