class Solution {
public:

    bool dfs(int curr, vector<vector<int>>& graph, vector<bool> vis, set<int>& ans, vector<int>& dp){
        if(dp[curr] != -1)
            return dp[curr];

        if(graph[curr].size() == 0){
            ans.insert(curr);
            return true;
        }

        vis[curr] = 1;
        int b = 0;
        for(auto child: graph[curr]){
            if(!vis[child]){
                vis[child] = 1;
                if(dfs(child, graph, vis, ans, dp))
                    b++;
                vis[child] = 0;
            }
        }
        if(b == graph[curr].size()){
            ans.insert(curr);
            return dp[curr] = true;
        }
        return dp[curr] = false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int> res;
        vector<bool> vis(n, 0);

        vector<int> dp(n, -1);
        for(int i=0;i<n;i++){
            if(!vis[i])
                dfs(i, graph, vis, res, dp);
        }

        vector<int>ans(res.begin(), res.end());
        return ans;
    }
};
