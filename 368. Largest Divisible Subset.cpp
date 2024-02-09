class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            for(int j=i-1;j>-1;j--){
                if(nums[i] % nums[j] == 0)
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        int idx = max_element(dp.begin(), dp.end()) - dp.begin();

        vector<int> ans;
        ans.push_back(nums[idx]);
        int val = dp[idx] - 1;

        for(int i=idx;i>-1;i--){
            if(dp[i] == val && ans.back() % nums[i] == 0){
                ans.push_back(nums[i]);
                val--;
            }
        }

        return ans;
    }
};
