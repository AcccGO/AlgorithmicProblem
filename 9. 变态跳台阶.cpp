class Solution
{
public:
    //     std::vector<int> saved_number;
    int jumpFloorII(int number)
    {
        if (number <= 0)
            return 0;
        //         if(number == 1) return 1;

        //         if(saved_number.empty())
        //             saved_number.resize(number, 0);

        //         int result = 1;
        //         for(int i=1; i<=number-1; i++){
        //             if(saved_number[i] == 0){
        //                 saved_number[i] = jumpFloorII(i);
        //             }
        //             result += saved_number[i];
        //         }
        //         return result;

        // 递归还是冗余了
        // 最后一个台阶肯定会被踩，它前面的每个台阶都会被踩或者不被踩，然后直接就是2^(n-1）
        // 用位运算更快

        return 1 << (number - 1);
    }
};