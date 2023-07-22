class Solution {
public:
    
    long long solution(int i, int n, vector<int>& nums, int x, int parity, vector<vector<long long>>& dp){
        if(i == n)
            return 0;
        
        
        if(dp[i][parity] != -1)
            return dp[i][parity];
        
        long long taken = 0;
        if(parity == nums[i] % 2)
            taken = nums[i] + solution(i+1, n, nums, x, parity, dp);
        else 
            taken = nums[i] - x + solution(i+1, n, nums, x, nums[i] % 2, dp);
        
        long long notTaken = solution(i+1, n, nums, x, parity, dp);
        
        return dp[i][parity] = max(taken, notTaken);
    }
    
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long> (2, -1));
        return nums[0] + solution(1, n, nums, x, nums[0] % 2, dp);
    }
};
