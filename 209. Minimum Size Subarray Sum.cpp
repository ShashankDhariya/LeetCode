class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MAX;
        int sum = 0;

        int i = 0;
        int j = 0;
        while(i < n && j < n){
            sum += nums[j++];
            while(i < n && sum >= target){
                ans = min(ans, j - i);
                sum -= nums[i++];
            }
        }
        return ans == INT_MAX? 0: ans;
    }
};
