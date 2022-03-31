class Solution
{
public:
    string LeftRotateString(string str, int n)
    {
        int str_length = str.size();
        if (str_length <= n) return str;

        return str.substr(n, str_length - n) + str.substr(0, n);
    }
};