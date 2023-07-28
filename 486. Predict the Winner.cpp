class Solution {
public:

    int solution(vector<int>& nums, int i, int j, int p, vector<vector<int>>& dp){
        if(i > j)
            return 0;

        if(i == j)
            return nums[i];
        
        if(dp[i][p] != -1)
            return dp[i][p];

        int score = 0;
        if(p)
            score = max(nums[i] + solution(nums, i+1, j, 0, dp), nums[j] + solution(nums, i, j-1, 0, dp));
        
        else 
            score = min(solution(nums, i+1, j, 1, dp), solution(nums, i, j-1, 1, dp));

        return dp[i][j] = score;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int num = solution(nums, 0, nums.size()-1, 1, dp);

        int totalScore = 0;
        for(auto n: nums)
            totalScore += n;

        int remaining = totalScore - num;    
        return num >= remaining;
    }
};
