class Solution {
public:
    
    bool solution(int i, int j, int sum, int& m, vector<int>& nums, unordered_map<string, bool>& dp){
        if(j - i <= 1)
            return 1;
        
        string str = to_string(i) + '-' + to_string(j);
        if(dp.find(str) != dp.end())
            return dp[str];
        
        bool start = 0;
        if(j - i > 1 && sum - nums[i] >= m)
            start = solution(i+1, j, sum-nums[i], m, nums, dp);
        bool end = 0;
        if(j - i > 1 && sum - nums[j] >= m)
            end = solution(i, j-1, sum-nums[j], m, nums, dp);
        
        return dp[str] = start + end;
    }
    
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        
        int sum = 0;
        for(auto num: nums)
            sum += num;
        
        unordered_map<string, bool> dp;
        return solution(0, n-1, sum, m, nums, dp);
    }
};
