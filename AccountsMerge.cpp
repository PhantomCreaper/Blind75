// 721. Accounts merge
class Solution {
private:
    string find(string s, unordered_map<string, string>& parent){
        if(parent[s] != s){
            parent[s] = find(parent[s], parent);
        }
        return parent[s];
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> emailToName;
        unordered_map<string, vector<string>> groups;
        for(auto& account: accounts){
            string name = account[0];
            string firstEmail = account[1];
            for(int i=1; i<account.size(); i++){
                string email = account[i];
                if(!parent.count(email)){
                    parent[email] = email;
                }
                emailToName[email] = name;
                if(i>1){
                    string root1 = find(firstEmail, parent);
                    string root2 = find(email, parent);
                    parent[root2] = root1;
                }
            }
        }

        for(auto& p:parent){
            string root = find(p.first, parent);
            groups[root].push_back(p.first);
        }

        vector<vector<string>> mergedAccounts;
        for(auto& group:groups){
            vector<string> emails = group.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[group.first]);
            mergedAccounts.push_back(emails);
        }
        return mergedAccounts;
    }
};
