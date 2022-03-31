class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int duplicate(vector<int>& numbers)
    {
        // write code here
        std::vector<int> hash_map(numbers.size(), 0);

        for (auto n : numbers) {
            if (hash_map[n] == 0)
                hash_map[n] = 1;
            else
                return n;
        }

        return -1;
    }
};