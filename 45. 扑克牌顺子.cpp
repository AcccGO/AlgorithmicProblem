class Solution
{
public:
    bool IsContinuous(vector<int> numbers)
    {
        // corner case
        if (numbers.empty()) return false;

        std::sort(numbers.begin(), numbers.end(), less<int>());
        auto last_number         = -1;
        auto random_number_count = 0;
        for (auto i : numbers) {
            if (i == 0)
                random_number_count++;
            else if (random_number_count < 0)
                return false;
            else if (last_number > 0) {
                auto gap = i - last_number - 1;
                if (gap < 0 || gap > random_number_count) return false;  //  > 0 : 避免两数相等的情况
                random_number_count -= gap;
            }

            last_number = i;
        }

        return true;
    }
};