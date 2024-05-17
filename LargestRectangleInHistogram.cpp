// 84. Largest Rectangle in Histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0);
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            while(!s.empty() && heights[i] < heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int width = s.empty()?i:i - s.top() - 1;
                maxArea = max(h*width, maxArea);
            }
            s.push(i);
        }

        return maxArea;
    }
};
