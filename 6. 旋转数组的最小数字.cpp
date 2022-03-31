class Solution
{
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        // corner case
        if (rotateArray.empty())
            return 0;
        if (rotateArray.size() == 1)
            return rotateArray[0];
        if (rotateArray.size() == 2)
            return min(rotateArray[0], rotateArray[1]);

        int start  = 0;
        int end    = rotateArray.size() - 1;
        int middle = end / 2.0;

        if (rotateArray[end] <= rotateArray[start]) {
            vector<int> new_array;
            if (rotateArray[middle] <= rotateArray[end])
                new_array.assign(rotateArray.begin(), rotateArray.begin() + middle + 1);
            else
                new_array.assign(rotateArray.begin() + middle + 1, rotateArray.end());

            return minNumberInRotateArray(new_array);
        }

        return rotateArray[start];
    }
};