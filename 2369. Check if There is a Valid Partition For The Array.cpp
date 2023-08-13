class Solution {
public:

    bool solution(int i, int& n, vector<int>& nums, vector<int>& dp){
        if(i >= n)
            return 1;

        if(dp[i] != -1)
            return dp[i];

        if(i+1 < n && nums[i+1] == nums[i]){
            if(solution(i+2, n, nums, dp))  return 1;
            if(i+2 < n && nums[i+2] == nums[i])
                if(solution(i+3, n, nums, dp))  return 1;
        }

        if(i+2 < n && nums[i+2] - nums[i+1] == 1 && nums[i+1] - nums[i] == 1){
            if(solution(i+3, n, nums, dp))  return 1;
        }

        return dp[i] = 0;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n, -1);
        return solution(0, n, nums, dp);
    }
};
