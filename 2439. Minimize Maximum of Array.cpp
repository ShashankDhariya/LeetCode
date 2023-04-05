class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            sum += nums[i];
            int res  = (sum + i) / (i+1);
            ans = max(ans, res);
        }
        return ans;
    }
};
