class Solution
{
public:
    int FirstNotRepeatingChar(string str)
    {
        //         map<char,std::pair<int, int>> first_pos_num;

        //         int index = 0;
        //         for(auto c: str){
        //             auto iter = first_pos_num.find(c);
        //             if(iter == first_pos_num.end()) first_pos_num.emplace(c, make_pair(index, 1));
        //             else iter->second.second++;

        //             index ++;
        //         }

        //         index = -1;
        //         for(auto i:first_pos_num){
        //             if((index < 0 || index > i.second.first) && i.second.second == 1) index = i.second.first;
        //         }

        //         return index;

        std::vector<int> chars(58, 0);
        for (auto c : str) {
            chars[(int)c - 65]++;
        }

        int index = 0;
        for (auto c : str) {
            if (chars[(int)c - 65] == 1) return index;
            index++;
        }
        return -1;  // corner case: empty string
    }
};