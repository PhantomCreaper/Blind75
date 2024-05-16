// 1235. Maximum profit job scheduling
class Solution {
public:
    struct Job{
        int start, end, profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for(int i = 0 ; i < n; i++){
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b){
            return a.end < b.end;
        });

        vector<pair<int, int>> dp = {{0, 0}};

        for(auto& job:jobs){
            int low = 0, high = dp.size() - 1;
            while(low<=high){
                int mid = (low+high)/2;
                if(dp[mid].first <= job.start){
                    low = mid + 1;
                } 
                else{
                    high = mid - 1;
                }
            }
            int currentProfit = dp[high].second + job.profit;
            if(currentProfit > dp.back().second){
                dp.push_back({job.end, currentProfit});
            }
        }

        return dp.back().second;
    }
};
