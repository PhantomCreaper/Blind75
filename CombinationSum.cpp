// 39. Combination Sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combinations;
        backtrack(candidates, target, results, combinations, 0);
        return results;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& results, vector<int>& combinations, int start){
        if(target == 0){
            results.push_back(combinations);
            return;
        }

        for(int i = start; i < candidates.size(); i++){
            if(candidates[i]<=target){
                combinations.push_back(candidates[i]);
                backtrack(candidates, target-candidates[i], results, combinations, i);
                combinations.pop_back();
            }
        }
    }
};
