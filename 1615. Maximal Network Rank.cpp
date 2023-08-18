class Solution {
public:

    int checkRank(int i, int j, vector<unordered_set<int>>& graph){
        int p = graph[i].size() + graph[j].size();

        if(graph[i].find(j) != graph[i].end())
            return p - 1;

        return p;
    }

    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> graph(n);
        for(auto r: roads){
            graph[r[0]].insert(r[1]);
            graph[r[1]].insert(r[0]);
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                ans = max(ans, checkRank(i, j, graph));
        }

        return ans;
    } 
};
