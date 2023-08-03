class Solution {
public:

    int mod = 1e9+7;
    int solution(int idx, int mask, vector<int>& nums,vector<vector<int>>& dp){
        if(mask == (1 << nums.size()) - 1)
            return 1;

        if(dp[idx][mask] != -1)
            return dp[idx][mask];

        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(mask & (1 << i))
                continue;

            if(mask == 0 || nums[idx] % nums[i] == 0 || nums[i] % nums[idx] == 0)
                ans = (ans + solution(i, mask | (1 << i), nums, dp) % mod) % mod;
        }
        
        return dp[idx][mask] = ans % mod;
    }
    
    int specialPerm(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> ((1 << 14) + 14, -1));
        return solution(0, 0, nums, dp);
    }
};
