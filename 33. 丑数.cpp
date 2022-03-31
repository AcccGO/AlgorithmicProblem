class Solution
{
public:
    int GetUglyNumber_Solution(int index)
    {
        //         corner case
        if (index < 7) return index;  // index还可能小于0！

        std::vector<int> num(index, 1);
        int a = 0;
        int b = 0;
        int c = 0;

        for (int i = 1; i < index; i++) {
            int min_num = min(num[a] * 2, min(num[b] * 3, num[c] * 5));
            num[i]      = min_num;

            if (min_num == (num[a] * 2)) a++;
            if (min_num == (num[b] * 3)) b++;
            if (min_num == (num[c] * 5)) c++;
        }

        return num.back();
    }
};