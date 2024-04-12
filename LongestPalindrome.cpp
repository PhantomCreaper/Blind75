// 409. Longest Palindrome
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size()==1){
            return 1;
        }
        unordered_map<char, int> map;
        for(char c:s){
            if(map[c] == 0){
                map[c] = 1;
            }
            else{
                map[c] += 1;
            }
        }
        int res = 0;
        bool center = false;
        for (const auto& pair : map){
            int count = pair.second;
            if(count%2 == 0){
                res += count;
            }
            else{
                res += count-1;
                center = true;
            }
        }
        if(center){
            res += 1;
        }
        return res;
    }
};
