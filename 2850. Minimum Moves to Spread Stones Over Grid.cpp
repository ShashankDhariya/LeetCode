class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        bool b = 1;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] == 0)
                    b = 0;
            }
        }
        if(b)   return 0;

        int res = INT_MAX;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j] == 0){
                    for(int x=0;x<3;x++){
                        for(int y=0;y<3;y++){

                            if(grid[x][y] > 1){
                                int dist = abs(i - x) + abs(j - y);
                                grid[x][y]--;
                                grid[i][j]++;
                                res = min(res, dist + minimumMoves(grid));
                                grid[i][j]--;
                                grid[x][y]++;
                            }
                        }
                    }
                }
            }
        }

        return res;
    }
};

OR
// Extra Space: zero's and one's position list

class Solution {
public:
    int solution(vector<vector<int>>& grid, map<pair<int, int>, int>& avail, map<pair<int, int>, int>& zero){
        bool b = 1;
        for(auto z: zero){
            if(z.second > 0)
                b = 0;
            for(auto a: avail){
                if(a.second > 1)   
                    b = 0;
            }
        }
        if(b)   return 0;

        int res = INT_MAX;
        for(auto& z: zero){
            if(z.second == 0)
                continue;

            auto zp = z.first;
            z.second--;
            for(auto& a: avail){
                if(a.second == 0)
                    continue;
                
                auto ap = a.first;
                int dist = abs(ap.first - zp.first) + abs(ap.second - zp.second);
    
                a.second--;
                res = min(res, dist + solution(grid, avail, zero));
                a.second++;
            }
            z.second++;
        }
        
        return res;
    }
    
    int minimumMoves(vector<vector<int>>& grid) {
        map<pair<int, int>, int> avail;
        map<pair<int, int>, int> zero;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int ele = grid[i][j];
                if(ele - 1 > 0)
                    avail[{i, j}] = ele - 1;
                if(ele == 0)
                    zero[{i, j}] = 1;
            }
        }
        
        return solution(grid, avail, zero);
    }
};
