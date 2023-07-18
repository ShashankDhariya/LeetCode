class Solution {
public:

    void solution(int col, int n, vector<vector<bool>>& board, unordered_map<int, bool>& r, unordered_map<int, bool>& du, unordered_map<int, bool>& dd, int& ans){
        if(col == n){
            ans++;
            return;
        }

        for(int row=0;row<n;row++){
            if(r[row] == 0 && du[n - 1 + col - row] == 0 && dd[row + col] == 0){
                r[row] = 1;
                du[n - 1 + col - row] = 1;
                dd[row + col] = 1;
                solution(col+1, n, board, r, du, dd, ans);
                r[row] = 0;
                du[n - 1 + col - row] = 0;
                dd[row + col] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;

        vector<vector<bool>> board(n, vector<bool> (n, 0));

        unordered_map<int, bool> r;
        unordered_map<int, bool> du;
        unordered_map<int, bool> dd;
        solution(0, n, board, r, du, dd, ans);
        return ans;
    }
};
