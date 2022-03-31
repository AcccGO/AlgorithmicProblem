class Solution
{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        // corner case
        if (pushV.empty() || popV.size() != pushV.size())
            return false;

        std::stack<int> test_stack;
        int pop_index  = 0;
        int stack_size = popV.size();

        for (auto& push_i : pushV) {
            test_stack.push(push_i);
            while (!test_stack.empty() && pop_index < stack_size && test_stack.top() == popV[pop_index]) {
                test_stack.pop();
                pop_index++;
            }
        }

        return test_stack.empty();
    }
};