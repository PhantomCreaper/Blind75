// 217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<int> count;
        for(int num:nums){
            if(count.find(num) != count.end()){
                return true;
            }
            count.insert(num);
        }
        return false;
    }
};
