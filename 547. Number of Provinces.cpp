class Solution {
public:

    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& vis){
        vis[curr] = 1;

        for(auto child: graph[curr]){
            if(!vis[child]){
                vis[child] = 1;
                dfs(child, graph, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)
                    continue;
                if(isConnected[i][j] == 1)
                    graph[i].push_back(j);
            }
        }

        int ans = 0;
        vector<bool> vis(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(i, graph, vis);
            }
        }
        return ans;
    }
};
