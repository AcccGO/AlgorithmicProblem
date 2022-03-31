class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char>> &matrix, string word)
    {
        // corner case
        if (matrix.empty() || matrix.front().empty())
            return false;
        if (word.empty())
            return true;

        // init
        std::vector<std::vector<bool>> if_visited(matrix.size(), std::vector<bool>(matrix[0].size(), false));

        // 只从开头开始递归可能无法遍历整个map会陷入死循环，因为只有字符匹配了才设置if_visited
        // return trace(0, 0, if_visited, matrix, word);

        // 很经典的递归+回溯，注意用flag剪枝
        auto flag = false;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.front().size(); j++) {
                if (matrix[i][j] == word[0]) {
                    trace(i, j, flag, if_visited, matrix, word);
                    if (flag == true)
                        return true;
                }
            }
        }

        return false;
    }

    void trace(int x, int y, bool &flag, std::vector<std::vector<bool>> &if_visited, const vector<vector<char>> &matrix, string word)
    {
        if (flag)
            return;  // 剪枝

        if (word.empty()) {
            flag = true;
            return;
        }

        if (x < 0 || x >= if_visited.size() || y < 0 || y >= if_visited.front().size() || if_visited[x][y] == true || matrix[x][y] != word[0])
            return;

        word             = word.substr(1);
        if_visited[x][y] = true;

        trace(x + 1, y, flag, if_visited, matrix, word);
        trace(x - 1, y, flag, if_visited, matrix, word);
        trace(x, y + 1, flag, if_visited, matrix, word);
        trace(x, y - 1, flag, if_visited, matrix, word);

        if_visited[x][y] = false;

        return;
    }
};