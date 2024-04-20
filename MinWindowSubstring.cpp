// 76. Minimum WindoW Substring
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }
        int l = 0;
        int r = 0;
        unordered_map<char, int> tmap;

        for(char c:t){
            tmap[c]++;
        }
        int req = tmap.size();
        unordered_map<char, int> window;
        int formed = 0;
        //int INT_MAX = numeric_limits<int>::max;
        int min_len = INT_MAX;
        int min_start = 0;

        while(r < s.length()){
            char c = s[r];
            window[c]++;
            if(tmap.count(c) && window[c] == tmap[c]){
                formed++;
            }
            while(l <= r && formed == req){
                c = s[l];
                if(r-l+1<min_len){
                    min_len = r-l+1;
                    min_start = l;
                }

                window[c]--;
                if(tmap.count(c) && window[c]<tmap[c]){
                    formed--;
                }
                l++;
            }
            r++;
        }
        return min_len == INT_MAX ? "":s.substr(min_start, min_len);
    }
};
