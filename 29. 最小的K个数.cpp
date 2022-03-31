class Solution
{
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        std::vector<int> result;
        if (k <= 0 || input.empty() || k > input.size()) return result;

        //         // 全排序 O(NlogN)
        //         std::sort(input.begin(), input.end(), less<int>());
        //         result.assign(input.begin(), input.begin() + k);
        //         return result;

        // 使用priority_queue
        // less是大顶堆，和sort比较函数相反
        priority_queue<int, vector<int>> pq;
        for (int i : input) {
            if (pq.size() < k)
                pq.push(i);
            else {
                if (i < pq.top()) {
                    pq.pop();
                    pq.push(i);
                }
            }
        }
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};