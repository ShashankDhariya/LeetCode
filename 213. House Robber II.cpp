class Solution {
public:

    int maxRob(int i, vector<int>& nums, bool first, vector<vector<int>>& dp){
        if(i >= nums.size())
            return 0;

        if(dp[i][first] != -1)
            return dp[i][first];

        if(i == nums.size() - 1) {
            if(first)   return dp[i][first] =  0;
            else    return dp[i][first] = nums[i];
        }            

        first = (i == 0)? 1: first;
        int rob = nums[i] + maxRob(i+2, nums, first, dp);
        first = (i == 0)? 0: first;
        int notRob = maxRob(i+1, nums, first, dp);

        return dp[i][first] = max(rob, notRob);
    }

    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (2, -1));
        return maxRob(0, nums, 0, dp);
    }
};
