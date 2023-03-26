class Solution {
public:

    void dfs(int curr, vector<int>& graph, vector<bool>& vis, unordered_map<int, int>& dist, int& ans){
        if(graph[curr] == -1)
            return;

        vis[curr] = 1;
        if(vis[graph[curr]] == 0){
            dist[graph[curr]] = dist[curr] + 1;
            dfs(graph[curr], graph, vis, dist, ans);
        }
        else if(dist[graph[curr]])
            ans = max(ans, dist[curr] - dist[graph[curr]] + 1);
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, 0);

        int ans = -1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, vis, dist, ans);
            }
        }
        return ans;
    }
};
