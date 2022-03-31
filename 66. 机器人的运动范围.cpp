class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        // corner case
        if (threshold < 0)
            return 0;

        std::vector<std::vector<int>> visited_map(rows);
        for (auto &i : visited_map) {
            i = std::vector<int>(cols, 0);
        }

        return find_way_result(0, 0, rows, cols, threshold, visited_map);
    }

    //     dfs
    //     1.从(0,0)开始走，每成功走一步标记当前位置为true,然后从当前位置往四个方向探索，
    //         返回1 + 4 个方向的探索值之和。
    //     2.探索时，判断当前节点是否可达的标准为：
    //         1）当前节点在矩阵内；
    //         2）当前节点未被访问过；
    //         3）当前节点满足limit限制。
    int find_way_result(int x, int y, int &rows, int &cols, int &threshold, std::vector<std::vector<int>> &visited_map)
    {
        if (x < 0 || x >= rows || y < 0 || y >= cols || count(x) + count(y) > threshold || visited_map[x][y] == 1)
            return 0;

        visited_map[x][y] = 1;
        return 1 + find_way_result(x + 1, y, rows, cols, threshold, visited_map) + find_way_result(x - 1, y, rows, cols, threshold, visited_map) + find_way_result(x, y + 1, rows, cols, threshold, visited_map) + find_way_result(x, y - 1, rows, cols, threshold, visited_map);
    }

    int count(int x)
    {
        int result = 0;
        while (x > 0) {
            result += x % 10;
            x /= 10;
        }

        return result;
    }
};