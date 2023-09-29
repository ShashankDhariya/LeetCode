class Solution {
public:
    vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[n].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int res = 0;
                for(auto d: dir){
                    int r = i + d.first;
                    int c = j + d.second;
                    if(r > -1 && r < m && c > -1 && c < n){
                        if(board[r][c] >= 1)
                            res++;
                    }
                }

                if(res == 3)
                    board[i][j] = (board[i][j] == 1)? 1: -1;

                else if(res > 3)
                    board[i][j] = (board[i][j] == 0)? 0: 2;

                else if(res < 2)
                    board[i][j] = (board[i][j] == 0)? 0: 2;
            }
        }

        for(auto& b: board){
            for(auto& cell: b){
                if(cell == 2 || cell == 0)
                    cell = 0;
                else 
                    cell = 1;
            }
        }
    }
};
