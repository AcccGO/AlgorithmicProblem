class Solution
{
public:
    void Insert(int num)
    {
        if (max_heap.empty() || max_heap.top() >= num)
            max_heap.push(num);
        else
            min_heap.push(num);

        // Adjust heap size
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (max_heap.size() == (min_heap.size() - 1)) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    double GetMedian()
    {
        if (max_heap.size() == min_heap.size()) return 0.5 * (min_heap.top() + max_heap.top());
        return max_heap.top();
    }

private:
    std::priority_queue<int, std::vector<int>, less<int>> max_heap;     // 大顶堆
    std::priority_queue<int, std::vector<int>, greater<int>> min_heap;  // 小顶堆
};