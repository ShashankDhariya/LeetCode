class Solution {
public:

    void dfs(int curr, vector<vector<int>>& graph, vector<bool>& vis, int& res){
        vis[curr] = 1;
        res++;
        for(auto child: graph[curr]){
            if(!vis[child]){
                vis[child] = 1;
                dfs(child, graph, vis, res);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<n;i++){
            double x1 = bombs[i][0];
            double y1 = bombs[i][1];
            double d =  bombs[i][2];
            for(int j=0;j<n;j++){
                if(i == j)
                    continue;

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                if(sqrt(((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))) <= d)
                    graph[i].push_back(j);
            }
        }

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int res = 0;
            vector<bool> vis(n, 0);
            dfs(i, graph, vis, res);
            ans = max(ans, res);
            cout<<endl;
        }

        return ans;
    }
};
