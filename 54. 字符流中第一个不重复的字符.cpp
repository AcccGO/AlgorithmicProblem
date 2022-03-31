class Solution
{
public:
    // Insert one char from stringstream
    void Insert(char ch)
    {
        if (hash_map.find(ch) == hash_map.end()) {
            str.push(ch);
            hash_map.emplace(ch, 1);
        } else {
            hash_map[ch]++;
        }
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while (!str.empty()) {
            if (hash_map[str.front()] == 1) return str.front();
            str.pop();
        }

        return '#';
    }

private:
    std::queue<char> str;
    std::unordered_map<char, int> hash_map;
};