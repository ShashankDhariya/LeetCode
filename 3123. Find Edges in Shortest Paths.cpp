class Solution {
public:
    
    bool dfs(int curr, int& dest, int minPath, vector<bool>& vis, vector<vector<pair<int, int>>>& graph, vector<vector<bool>>& res){
        if(minPath < 0)
            return 0;
         
        if(curr == dest)
            return (minPath == 0);
        
        bool ans = 0;
        vis[curr] = 1;
        for(auto child: graph[curr]){
            if(vis[child.first])
                continue;
            
            bool r = dfs(child.first, dest, minPath - child.second, vis, graph, res);
            if(r) {
                res[curr][child.first] = 1;
                ans = 1;
            }
        }
        vis[curr] = 0;
        
        return ans;
    }
    
    int dijktra(int n, vector<vector<pair<int, int>>>& graph){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<bool> vis(n, 0);
        pq.push({0, 0});
        vis[0] = 1;
        
        vector<int> path(n, 1e9);
        path[0] = 0;
        while(!pq.empty()){
            int curr = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            vis[curr] =  1;
            
            for(auto child: graph[curr]){
                if(vis[child.first])
                    continue;
                
                if(path[child.first] > cost + child.second){
                    path[child.first] = cost + child.second;
                    pq.push({path[child.first], child.first});
                }
            }
        }
        
        return path[n-1];
    }
    
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> ans;
        
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }
        
        int minPath = dijktra(n, graph);
        
        vector<bool> vis(n, 0);
        vector<vector<bool>> res(n, vector<bool> (n, 0));
        n -= 1;
        dfs(0, n, minPath, vis, graph, res);
        
        for(int i=0;i<edges.size();i++){
            if(res[edges[i][0]][edges[i][1]] || res[edges[i][1]][edges[i][0]])
                ans.push_back(1);
            else 
                ans.push_back(0);
        }
        
        return ans;
    }
};
