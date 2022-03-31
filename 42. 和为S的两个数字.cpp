class Solution
{
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        vector<int> result;
        if (array.empty()) return result;
        if (array.front() > sum) return result;

        int start = 0, end = array.size() - 1;
        while (start < end) {
            int tmp_sum = array[start] + array[end];
            if (tmp_sum < sum)
                start++;
            else if (tmp_sum > sum)
                end--;
            else {
                //                 if(result.empty()){
                result.emplace_back(array[start]);
                result.emplace_back(array[end]);
                return result;
                //                 }else{
                //                     if(array[start] * array[end] < result[0] * result[1]){
                //                         result[0] = array[start];
                //                         result[1] = array[end];
                //                     }
                //                 }

                //                 start++;
                //                 end--;
            }
        }

        return result;
    }
};