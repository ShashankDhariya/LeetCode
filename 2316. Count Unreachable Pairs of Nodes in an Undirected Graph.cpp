class Solution {
public:

    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& vis, long long& res){
        vis[curr] = 1;
        res++;
        for(auto child: graph[curr]){
            if(!vis[child])
                dfs(child, graph, vis, res);
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, 0);

        for(auto e: edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        long long ans = (long long)n*(n-1)/2;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                long long res = 0;
                dfs(i, graph, vis, res);
                ans -= (res*(res-1)) / 2;
            }
        }

        return ans;
    }
};
