class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size() == 1)
            return 0;

        int n = graph.size();
        int finalState = (1 << n) - 1;

        queue<pair<int, int>> q;
        for(int i=0;i<n;i++)
            q.push({i, 1 << i});

        vector<vector<int>> vis(n, vector<int> (finalState + 1, 0));

        int shortestPath = 0;
        while(!q.empty()){
            int size = q.size();
            shortestPath++;

            for(int i=0;i<size;i++){
                int nodeId = q.front().first;
                int visNodeBitState = q.front().second;
                q.pop();
                for(auto child: graph[nodeId]){
                    int newBitState = (1 << child) | visNodeBitState;
                    if(vis[child][newBitState] == 1)
                        continue;

                    vis[child][newBitState] = 1;
                    if(newBitState == finalState)
                        return shortestPath;

                    q.push({child, newBitState});
                }
            }
        }

        return -1;
    }
};
