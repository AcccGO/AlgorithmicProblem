class Solution
{
public:
    string PrintMinNumber(vector<int> numbers)
    {
        std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
            auto sa = std::to_string(a);
            auto sb = std::to_string(b);
            return sa + sb <= sb + sa;
        });

        std::string result;
        for (auto i : numbers)
            result += std::to_string(i);

        return result;
    }
};