class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> graph(n);
        for(int i=0;i<n;i++){            
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=1;j<n;j++){
                if(i == j)
                    continue;
                int x2 = points[j][0];
                int y2 = points[j][1];  
                int weight = abs(x1-x2) + abs(y1-y2);
                graph[i].push_back({j, weight});
            }
        }   

        int ans = 0;
        vector<int> vis(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, 0});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            int weight = curr.first;
            if(vis[node] == 1)
                continue;
            vis[node] = 1;
            
            ans += weight;
            for(auto child: graph[node]){
                int cNode = child.first;
                int cWeight = child.second;
                if(vis[cNode] == 0)
                    pq.push({cWeight, cNode});
            }
        }

        return ans;
    }
};
