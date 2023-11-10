class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> mp;
        for(auto& adj: adjacentPairs){
            mp[adj[0]].push_back(adj[1]);
            mp[adj[1]].push_back(adj[0]);
        }

        vector<int> ans;
        for(auto& s: mp){
            if(s.second.size() == 1){
                ans.push_back(s.first);
                ans.push_back(s.second[0]);
                break;
            }
        }

        while(ans.size() < adjacentPairs.size() + 1){
            auto curr = ans.back();
            auto prev = ans[ans.size() - 2];
            auto next = mp[curr];
            if(next[0] != prev)
                ans.push_back(next[0]);

            else 
                ans.push_back(next[1]);
        }

        return ans;
    }
};
