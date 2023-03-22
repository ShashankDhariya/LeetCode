class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<vector<pair<int, int>>> graph(n+1);
        vector<bool> vis(n+1, 0);

        for(auto v: roads){
            graph[v[0]].push_back({v[1], v[2]});
            graph[v[1]].push_back({v[0], v[2]});
        }

        queue<int> q;
        q.push(1);
        vis[1] = 1;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            vis[curr] = 1;
            for(auto child: graph[curr]){
                ans = min(ans, child.second);
                if(!vis[child.first])
                    q.push(child.first);
            }
        }
        return ans;
    }
};
