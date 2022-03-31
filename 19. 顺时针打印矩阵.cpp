class Solution
{
public:
    vector<int> printMatrix(vector<vector<int> > matrix)
    {
        vector<int> result;

        // corner case
        if (matrix.empty() || matrix[0].empty()) return result;

        int height = matrix.size();
        int width  = matrix[0].size();

        int left  = 0;
        int right = width - 1;
        int up    = 0;
        int down  = height - 1;

        while (left <= right && up <= down) {
            for (int i = left; i <= right; i++)
                result.emplace_back(matrix[up][i]);

            for (int i = up + 1; i < down; i++)
                result.emplace_back(matrix[i][right]);

            if (down > up)
                for (int i = right; i >= left; i--)
                    result.emplace_back(matrix[down][i]);

            if (left < right)
                for (int i = down - 1; i > up; i--)
                    result.emplace_back(matrix[i][left]);

            left++;
            right--;
            up++;
            down--;
        }

        return result;
    }
};