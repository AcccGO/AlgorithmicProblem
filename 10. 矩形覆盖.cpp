class Solution
{
public:
    std::vector<int> saved_number;
    int rectCover(int number)
    {
        // corner case
        // return case
        if (number <= 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;

        if (saved_number.empty())
            saved_number.resize(number, 0);

        // 还是斐波那契数列
        if (saved_number[number - 1] == 0)
            saved_number[number - 1] = rectCover(number - 1);
        if (saved_number[number - 2] == 0)
            saved_number[number - 2] = rectCover(number - 2);

        // 复杂度还是O(N)
        // 好像还是直接迭代更好
        return saved_number[number - 1] + saved_number[number - 2];
    }
};