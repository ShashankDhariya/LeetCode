class Solution {
public:

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double prob = 0.0;
        vector<vector<pair<int, double>>> graph(n);

        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;
        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto child: graph[curr]){
                double prob = child.second;
                double currProb = prob * dist[curr];

                if(currProb > dist[child.first]){
                    dist[child.first] = currProb;
                    q.push(child.first);
                }
            }
        }
        return dist[end];
    }
};
