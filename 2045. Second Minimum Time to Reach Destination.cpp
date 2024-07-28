class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n+1);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        q.push({1, 0});
        vector<int> dist1(n+1, INT_MAX);
        vector<int> dist2(n+1, INT_MAX);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(auto child: graph[curr.first]){
                int newDist = curr.second + 1;
                if(newDist < dist1[child]){
                    dist2[child] = dist1[child];
                    dist1[child] = newDist;
                    q.push({child, newDist});
                }

                else if(newDist < dist2[child] && newDist > dist1[child]){
                    dist2[child] = newDist;
                    q.push({child, newDist});
                }
            }
        }

        if(dist2[n] == INT_MAX)
            return -1;

        int ans = 0;
        for(int i=0;i<dist2[n];i++){
            int green = ans / change;
            if(green % 2)
                ans = (green + 1) * change;

            ans += time;
        }

        return ans;
    }
};
