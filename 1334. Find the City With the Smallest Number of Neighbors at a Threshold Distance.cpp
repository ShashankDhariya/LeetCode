class Solution {
public:

    void solution(int& n, vector<vector<int>>& edges, int& d, vector<vector<int>>& dist){
        for(int i=0;i<n;i++)
            dist[i][i] = 0;

        for(auto edge: edges){
            if(edge[2] <= d){
                dist[edge[0]][edge[1]] = edge[2];
                dist[edge[1]][edge[0]] = edge[2];
            }
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int> (n, 1e9));
        solution(n, edges, distanceThreshold, dist);

        int ans = 0;
        int minCities = 1e9;
        for(int i=0;i<n;i++){
            int cities = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold)
                    cities++;
            }

            if(cities <= minCities){
                minCities = cities;
                ans = i;
            }
        }

        return ans;
    }
};
