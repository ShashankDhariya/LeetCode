class Solution {
public:
    
    int solution(int start, int end, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(start >= end)
            return 0;
        
        if(dp[start][end] != -1)
            return dp[start][end];
        
        int op1 = 0;
        if(nums[start] + nums[start+1] == sum)
            op1 = 1 + solution(start+2, end, sum, nums, dp);
        
        int op2 = 0;
        if(nums[start] + nums[end] == sum)
            op2 = 1 + solution(start+1, end-1, sum, nums, dp);
        
        int op3 = 0;
        if(nums[end-1] + nums[end] == sum)
            op3 = 1 + solution(start, end-2, sum, nums, dp);
        
        return dp[start][end] = max({op1, op2, op3});
    }
    
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> dp1(n, vector<int> (n, -1));
        int op1 = solution(0, n-1, nums[0]+nums[1], nums, dp1);
        
        vector<vector<int>> dp2(n, vector<int> (n, -1));
        int op2 = solution(0, n-1, nums[n-2]+nums[n-1], nums, dp2);
        
        vector<vector<int>> dp3(n, vector<int> (n, -1));
        int op3 = solution(0, n-1, nums[0]+nums[n-1], nums, dp3);
        
        return max({op1, op2, op3});
    }
};
