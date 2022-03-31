class Solution
{
public:
    void push(int value)
    {
        stack0.push(value);
        if (stack1.empty() || stack1.top() >= value)
            stack1.push(value);
    }

    void pop()
    {
        if (stack0.top() == stack1.top())
            stack1.pop();
        stack0.pop();
    }

    int top()
    {
        return stack0.top();
    }

    int min()
    {
        return stack1.top();
    }

private:
    // 0 ： 正常存储数据
    // 1 ： 存储最小数据
    std::stack<int> stack0, stack1;
};