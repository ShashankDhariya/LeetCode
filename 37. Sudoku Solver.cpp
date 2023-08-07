class Solution {
public:

    bool canUse(int row, int col, char val, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col] == val)
                return 0;

            if(board[row][i] == val)
                return 0;

            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
                return 0;
        }
        return 1;
    }

    bool solution(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.')
                    continue;
                for(char v='1';v<='9';v++){
                    if(canUse(i, j, v, board)){
                        board[i][j] = v;
                        if(solution(board))
                            return 1;
                        else
                            board[i][j] = '.';
                    }
                }
                return 0;
            }
        }
        return 1;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solution(board);
    }
};
