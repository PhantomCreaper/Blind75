// 242. Valid Anagram
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        if(s.length()!=t.length())
            return false;
        for(char c : s){
            count[c]++;
        }
        for(char c : t){
            if(--count[c]<0){
                return false;
            }
        }
        return true;
    }
};
