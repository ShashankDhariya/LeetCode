class Solution {
public:

    vector<vector<int>> dist = {{0, 1}, {0, -1},{1, 0},{-1,0}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int max_len = -1;
        pair<int,int> start;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '@')
                    start = {i, j};
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    max_len = max(grid[i][j] - 'a' + 1, max_len);
            }
        }

        int ans = 0;
        queue<vector<int>> q;
        q.push({start.first, start.second, 0});
        unordered_set<string> vis;
        vis.insert(to_string(0) + " " + to_string(start.first) + " " + to_string(start.second));

        while(!q.empty()){
            int size = q.size();
            for(int k=0;k<size;k++){
                auto curr = q.front();
                q.pop();

                if(curr[2] == (1 << max_len) - 1)
                    return ans;

                for(int d=0;d<4;d++){
                    int i = curr[0] + dist[d][0];
                    int j = curr[1] + dist[d][1];
                    int keys = curr[2];

                    if(i < m && i > -1 && j < n && j > -1){
                        char c = grid[i][j];
                        if(c == '#')
                            continue;
                        
                        if(c >= 'a' && c <= 'f')
                            keys |= 1 << (c - 'a');

                        if(c >= 'A' && c <= 'F' && (1 << (c - 'A') & keys) == 0)
                            continue;

                        if(!vis.count(to_string(keys) + " " + to_string(i) + " " + to_string(j))){
                            vis.insert(to_string(keys) + " " + to_string(i) + " " + to_string(j));
                            q.push({i, j, keys});
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
