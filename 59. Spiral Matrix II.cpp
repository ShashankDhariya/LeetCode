class Solution {
public:

    void matrix(int i, int j, int& n, int num, vector<vector<int>>& ans, int move){
        ans[i][j] = num++;

        if(move == 1 && j+1 < n && !ans[i][j+1]){
            matrix(i, j+1, n, num, ans, 1);
            return;
        }

        move = 2;
        if(move == 2 && i+1 < n && !ans[i+1][j]){
            matrix(i+1, j, n, num, ans, 2);
            return;
        }

        move = 3;
        if(move == 3 && j-1 > -1 && !ans[i][j-1]){
            matrix(i, j-1, n, num, ans, 3);    
            return;
        }

        move = 4;
        if(move == 4 && i-1 > -1 && !ans[i-1][j]){
            matrix(i-1, j, n, num, ans, 4);    
            return;
        }
        move = 1;
        if(move == 1 && j+1 < n && !ans[i][j+1]){
            matrix(i, j+1, n, num, ans, 1);
            return;
        }
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 0));
        matrix(0, 0, n, 1, ans, 1);
        return ans;
    }
};
