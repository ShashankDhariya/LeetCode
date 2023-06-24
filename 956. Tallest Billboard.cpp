class Solution {
public:
    int board(int i, int diff, vector<int>& rods, vector<vector<int>>& dp){
        if(i == rods.size()){
            if(diff == 0)
                return 0;
            return INT_MIN;
        }

        int& ans = dp[i][diff + 5000];
        if(ans != -1)
            return ans;

        int notTake = board(i+1, diff, rods, dp);
        int s1 = board(i+1, diff + rods[i], rods, dp);
        int s2 = rods[i] + board(i+1, diff - rods[i], rods, dp);

        return ans = max({notTake, s1, s2});
    }

    int tallestBillboard(vector<int>& rods) {
        vector<vector<int>> dp(21, vector<int> (2 * 5000 + 1, -1));
        return board(0, 0, rods, dp);
    }
};
