// 54. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;

        int top = 0, right = n-1, bottom = m-1, left = 0;
        while(result.size() < m*n){
            for(int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;
            
            for(int j = top; j <= bottom; j++)
                result.push_back(matrix[j][right]);
            right--;
            
            if(top<=bottom){
                for(int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
                
            }
            if(left<=right){
                for(int j = bottom; j >= top; j--)
                    result.push_back(matrix[j][left]);
                left++;  
            }
        }
        return result;
    }
};
