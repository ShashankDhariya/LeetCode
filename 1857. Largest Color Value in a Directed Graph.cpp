class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n, vector<int>());
        vector<int> indegree(n, 0);

        for(auto e: edges){
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<vector<int>> dp(n, vector<int> (26, 0));
        for(int i=0;i<n;i++)
            dp[i][colors[i] - 'a']++;

        int ans = 0;
        int visited = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            visited++;
            for(auto v: graph[u]){
                for(int i=0;i<26;i++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (colors[v] - 'a' == i? 1:0));
                }
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v);
            }
            ans = max(ans, *max_element(dp[u].begin(), dp[u].end()));
        }
        cout<<visited;
        return visited == n? ans: -1;
    }
};
