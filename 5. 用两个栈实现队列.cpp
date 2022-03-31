class Solution
{
public:
    void push(int node)
    {
        stack1.push(node);
    }

    int pop()
    {
        if (stack1.empty() && stack2.empty())
            return 0;  // 这应该是用户事先用另一个empty()函数判断好才对，否则这里应该直接报错

        auto pop_stack2 = [&]() -> int {
            auto result = stack2.top();
            stack2.pop();
            return result;
        };

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        return pop_stack2();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};