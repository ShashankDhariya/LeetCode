class Solution {
public:
    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& vis, int& ans){
        vis[curr] = 1;
        for(auto child: graph[curr]){
            if(!vis[abs(child)]){
                ans += (child > 0);
                dfs(abs(child), graph, vis, ans);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, 0);

        for(auto c: connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(-c[0]);
        }
        int ans = 0;
        dfs(0, graph, vis, ans);
        return ans;
    }
};
