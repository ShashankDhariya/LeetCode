class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        int last = n-1;

        for(int i=n-2;i>-1;i--){
            if(i+nums[i] >= last)
                dp[i] = 1;
            
            else {
                int mini = INT_MAX;
                for(int k=1;k<=nums[i];k++){
                    if(i+k >= n)
                        break;
                    mini = min(mini, dp[i+k]);
                }
                if(mini == INT_MAX)
                    continue;
                else
                    dp[i] = 1 + mini;
            }
        }
        return dp[0];
    }
};
