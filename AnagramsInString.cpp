// 438. Find All Anagrams in a String
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;

        vector<int> pCount(26, 0);
        vector<int> sCount(26, 0);

        for (char c : p) {
            pCount[c - 'a']++;
        }

        int pLen = p.length();
        int sLen = s.length();

        for (int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
        }

        if (sCount == pCount) {
            result.push_back(0);
        }

        for (int i = pLen; i < sLen; i++) {
            sCount[s[i] - 'a']++;
            sCount[s[i - pLen] - 'a']--;

            if (sCount == pCount) {
                result.push_back(i - pLen + 1);
            }
        }

        return result;
    }
};
