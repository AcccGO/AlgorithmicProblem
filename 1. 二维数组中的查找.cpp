class Solution
{
public:
    bool Find(int target, vector<vector<int>> array)
    {
        // corner case
        if (array.empty())
            return false;
        if (array.front().empty())
            return false;
        if (array.front().front() > target)
            return false;
        if (array.back().back() < target)
            return false;

        // 从左下角开始搜索
        int width  = array[0].size();
        int height = array.size();
        int row    = height - 1;
        int col    = 0;

        while (col < width && row >= 0) {
            if (array[row][col] == target)
                return true;
            if (array[row][col] < target)
                col++;
            else
                row--;
        }

        return false;
    }
};