class Solution {
public:

    int solution(int i, int& m, int n, int x, vector<int>& nums, vector<vector<int>>& dp){
        if(i == n)
            return x == m;

        if(dp[i][x] != -1)
            return dp[i][x];

        int taken = solution(i+1, m, n, x | nums[i], nums, dp);
        int notTaken = solution(i+1, m, n, x, nums, dp);

        return dp[i][x] = taken + notTaken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int m = 0;
        for(auto num: nums)
            m |= num;

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (m+1, -1));
        return solution(0, m, n, 0, nums, dp);
    }
};
