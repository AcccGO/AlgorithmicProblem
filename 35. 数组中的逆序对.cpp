class Solution
{
public:
    int InversePairs(vector<int> data)
    {
        int result = 0;
        if (data.empty()) return result;

        merge_sort(data, result, 0, data.size() - 1);
        return result;
    }

    // 归并排序， 需要会写
    // 时间复杂度o(nlog(n)),空间复杂度o(n)
    void merge_sort(vector<int>& data, int& result, int left, int right)
    {
        if (left < right) {
            int mid = (left + right) >> 1;
            merge_sort(data, result, left, mid);
            merge_sort(data, result, mid + 1, right);

            std::vector<int> tmp(right - left + 1);
            int index = tmp.size() - 1;

            int i = mid, j = right;

            for (; i >= left && j >= mid + 1;) {
                // 关键点在于：
                // 1：j的比前面的i小，那么后面一组所有还剩下没遍历的j之前数字都可以和i组成逆序对；将更大的i压入临时vector
                // 2：否则，将j压入临时vector
                // 3：和归并排序一样，需要对合并的数组重新排序，否则会影响上一层merge时的计数结果。即两段子序列merge之后应返回有序结果。
                if (data[i] > data[j]) {
                    result += (j - mid);   // key!
                    result %= 1000000007;  // 易犯错： 要在这一步加好之后就模除，不然返回最后结果再操作的话，测试样例一大，会数值越界
                    tmp[index--] = data[i--];
                } else {
                    tmp[index--] = data[j--];
                }
            }

            while (i >= left) {
                tmp[index--] = data[i--];
            }

            while (j >= mid + 1) {
                tmp[index--] = data[j--];
            }

            for (int k = left; k <= right; k++) {
                data[k] = tmp[k - left];
            }
        }
        return;
    }
};