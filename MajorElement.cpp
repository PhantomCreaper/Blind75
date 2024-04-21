// 169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int maximum = 0;
        int result;
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
            if(count[nums[i]]>maximum){
                maximum = count[nums[i]];
                result = nums[i];
            }
        }
        return result;
    }
};
