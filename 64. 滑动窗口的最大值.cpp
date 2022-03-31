class Solution
{
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        std::vector<int> result;
        // corner case
        if (size > num.size() || size == 0) return result;

        int front          = 0;
        int end            = size - 1;
        int last_max_index = 0;

        auto traverse = [&](const auto& front, const auto& end, auto& max_int) {
            max_int = num[front];
            for (int i = front + 1; i <= end; i++) {
                max_int        = std::max(max_int, num[i]);
                last_max_index = max_int == num[i] ? i : last_max_index;
            }
        };

        while (end < num.size()) {
            int max_int = 0;

            if (result.empty()) {
                traverse(front, end, max_int);  // first window
            } else {
                if (num[end] > result.back()) {  // if the end if larger than the previous window
                    max_int        = num[end];
                    last_max_index = end;
                } else if (last_max_index >= front && last_max_index <= end) {  // if the last index is in this window
                    max_int        = result.back();
                    last_max_index = last_max_index;
                } else {
                    traverse(front, end, max_int);  // traverse again
                }
            }

            result.emplace_back(max_int);
            front++;
            end++;
        }

        return result;
    }
};