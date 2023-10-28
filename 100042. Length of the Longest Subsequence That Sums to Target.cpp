class Solution {
public:
    
    int solution(int i, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(target == 0)
            return 0;
        
        if(target < 0)
            return -1e9;
        
        if(i == nums.size())
            return -1e9;        
        
        if(dp[i][target] != -1)
            return dp[i][target];
        
        int taken = 1 + solution(i+1, nums, target-nums[i], dp);
        int notTaken = solution(i+1, nums, target, dp);
        
        return dp[i][target] = max(taken, notTaken);
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        int ans = solution(0, nums, target, dp);
        return ans <= 0? -1: ans;
    }
};
