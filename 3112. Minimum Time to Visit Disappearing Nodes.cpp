class Solution {
public:
    
    void dijktras(int curr, vector<vector<pair<int, int>>>& graph, vector<int>& res, vector<int>& disappear){   
        if(curr != 0 && res[curr] >= disappear[curr])
            res[curr] = 1e7;
        
        if(res[curr] == -1e7)
            return;
        
        for(auto node: graph[curr]){
            int child = node.first;
            int len = node.second;
            
            if(res[child] > (res[curr] + len)){
                res[child] = res[curr] + len;
                dijktras(child, graph, res, disappear);
            }
        }
    }
    
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int len = edge[2];
            graph[u].push_back({v, len});
            graph[v].push_back({u, len});
        }
        
        vector<int> res(n, 1e9);
        res[0] = 0;
        dijktras(0, graph, res, disappear);
        
        for(auto& r: res){
            if(r == 1e9 || r == 1e7)
                r = -1;
        }
        
        return res;
    }
};
