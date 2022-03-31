class Solution
{
public:
    int jumpFloor(int number)
    {
        // corner case
        // return case
        if (number <= 0)
            return 0;
        if (number == 1)
            return 1;
        if (number == 2)
            return 2;

        // 对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来，所以
        // F(n) = F(n-1) + F(n-2)
        // 可以枚举开头的情况就能发现规律
        return jumpFloor(number - 1) + jumpFloor(number - 2);
    }
};