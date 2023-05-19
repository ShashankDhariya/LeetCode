class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for(int i=0;i<n;i++){
            if(color[i] != 0)
                continue;
                
            queue<int> q;
            q.push(i);
            color[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto child: graph[node]){
                    if(color[child] == color[node])
                        return false;
                    else if(color[child] == 0){
                        color[child] = -color[node];
                        q.push(child);
                    }
                }
            }
        }
        return true;
    }
};
