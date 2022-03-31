class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array)
    {
        // write code here
        std::vector<int> result;
        map<int, int> table;

        for (auto& i : array) {
            if (table.find(i) == table.end()) {
                table.emplace(i, 1);
            } else {
                table[i]++;
            }
        }

        for (auto& i : table) {
            if (i.second == 1) result.emplace_back(i.first);
            if (result.size() == 2) break;
        }

        std::sort(result.begin(), result.end());
        return result;
    }
};