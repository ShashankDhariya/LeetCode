class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> dp;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            dp[nums[i] + 1] = max(dp[nums[i] + 1], 1 + dp[nums[i]]);
            dp[nums[i]] = max(dp[nums[i]], 1 + dp[nums[i] - 1]);
        }
        
        int ans = 0;
        for(auto d: dp)
            ans = max(ans, d.second);
        
        return ans;
    }
};
