class Solution
{
public:
    bool m_VerifySquenceOfBST(const vector<int>& sequence)
    {
        // corner case
        if (sequence.empty() || sequence.size() == 1) return true;
        int root  = sequence.back();
        int size  = sequence.size();
        int index = size - 1;

        for (int i = 0; i < size - 1; i++) {
            if (sequence[i] > root && index > i) index = i;
            if (sequence[i] < root && i > index) return false;
        }

        std::vector<int> left(sequence.begin(), sequence.begin() + index);
        std::vector<int> right(sequence.begin() + index, sequence.end() - 1);
        if (m_VerifySquenceOfBST(left) && m_VerifySquenceOfBST(right)) return true;
        return false;
    }

    bool VerifySquenceOfBST(vector<int> sequence)
    {
        // corner case
        if (sequence.empty()) return false;  // 为什么单独拎出来一个函数：因为测试样例里对一棵空树要求返回false，和上面的判断相悖
        return m_VerifySquenceOfBST(sequence);
    }
};