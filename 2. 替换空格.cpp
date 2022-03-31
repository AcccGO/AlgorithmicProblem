class Solution
{
public:
    void replaceSpace(char *str, int length)
    {
        // corner case
        if (length == 0)
            return;

        // 先找到空格数目
        // O(N)
        int space_num = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == 0x20)
                space_num++;
        }

        // 分配新的指针的地址
        const int new_length = length + space_num;
        char *new_str        = new char[new_length];

        // 填充新的字符串
        int j = 0;
        for (int i = 0; i < length; i++) {
            if (str[i] == 0x20) {
                new_str[j]     = '%';
                new_str[j + 1] = '2';
                new_str[j + 2] = '0';

                j += 3;
            } else {
                new_str[j] = str[i];

                j++;
            }
        }

        // 如果直接修改指针指向会提交错误
        // 因此拷贝复制
        // 删除原先new的内容
        strncpy(str, new_str, new_length);
        delete[] new_str;
    }
};