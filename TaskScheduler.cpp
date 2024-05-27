class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> f;
        for(char c:tasks){
            f[c]++;
        }

        priority_queue<int> frequency;
        for(auto& c:f){
            frequency.push(c.second);
        }
        int time = 0;
        while(!frequency.empty()){
            int curr = 0;
            vector<int> temp;
            for(int i = 0; i <=n; i++){
                if(!frequency.empty()){
                    temp.push_back(frequency.top());
                    frequency.pop();
                    curr++;
                }
            }

            for(int c:temp){
                if(--c > 0){
                    frequency.push(c);
                }
            }
            time += !frequency.empty() ? n+1:curr;
        }

        return time;
    }
};
