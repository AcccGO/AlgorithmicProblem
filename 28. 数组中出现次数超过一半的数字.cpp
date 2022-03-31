class Solution
{
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        int half_size = (int)std::floor(numbers.size() * 0.5);
        unordered_map<int, int> m;

        for (auto i : numbers) {
            if (m.find(i) == m.end()) {
                m.emplace(i, 1);
            } else {
                m[i]++;
            }

            if (m[i] > half_size) return i;
        }

        return 0;
    }
};