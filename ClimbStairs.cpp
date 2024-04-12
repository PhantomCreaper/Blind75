class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, numeric_limits<int>::max());
        int one = 1;
        int two = 1;
        if(n == 1){
            return 1;
        }
        for(int i = 0; i < n-1; i++){
            int temp = one;
            one = one+two;
            two = temp;
        }
        return one;
    }
};
