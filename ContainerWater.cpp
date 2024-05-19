// 11. Container With Most Water.
class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left<=right){
            int diff = right - left;
            if(height[left] < height[right]){
                maxArea = max(height[left] * diff, maxArea);
                left++;
            }
            else{
                maxArea = max(height[right] * diff, maxArea);
                right--;
            }
        }
        return maxArea;
    }
};
