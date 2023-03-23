class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1)
            return -1;

        vector<vector<int>> graph(n);
        vector<bool> vis(n, 0);

        for(auto c: connections){
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        int res = 0;
        for(int i=0;i<n;i++){
            if(vis[i])
                continue;

            res++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()){
                auto curr = q.front();
                q.pop();
                for(auto num: graph[curr]){
                    if(!vis[num]){
                        q.push(num);
                        vis[num] = 1;
                    }
                }
            }
        }
        return res - 1;
    }
};
