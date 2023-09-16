class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        dist[0][0] = 0;

        pq.push({0, {0, 0}});

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int diff = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == m-1 && col == n-1)
                return diff;

            for(auto d: dir){
                int r = row + d.first;
                int c = col + d.second;

                if(r > -1 && r < m && c > -1 && c < n){
                    int currEffort = max(diff, abs(heights[row][col] - heights[r][c]));
                    if(currEffort < dist[r][c]){
                        dist[r][c] = currEffort;
                        pq.push({dist[r][c], {r, c}});
                    }
                }
            }

        }

        return 0;
    }
};
