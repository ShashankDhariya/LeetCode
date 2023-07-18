class Solution {
public:
    void solution(int col, int n, vector<string>& board, vector<vector<string>>& ans, unordered_map<int, bool>& r, unordered_map<int, bool>& du, unordered_map<int, bool>& dd){
        if(col == n){
            ans.push_back(board);
            return;
        }            

        for(int row=0;row<n;row++){
            if(r[row] == 0 && du[n - 1 + (col-row)] == 0 && dd[row+col] == 0){
                board[row][col] = 'Q';
                r[row] = 1;
                du[n - 1 + (col-row)] = 1;
                dd[row+col] = 1;
                solution(col+1, n, board, ans, r, du, dd);
                board[row][col] = '.';
                r[row] = 0;
                du[n - 1 + (col-row)] = 0;
                dd[row+col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);

        string str = "";
        for(int i=0;i<n;i++)
            str.push_back('.');

        for(int i=0;i<n;i++)
            board[i] = str;

        unordered_map<int, bool> r;
        unordered_map<int, bool> du;
        unordered_map<int, bool> dd;
        solution(0, n, board, ans, r, du, dd);
        return ans;
    }
};
