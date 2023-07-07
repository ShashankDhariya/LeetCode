class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        int pre = 1;
        int suf = 1;
        for(int i=0;i<n;i++){
            pre *= nums[i];
            suf *= nums[n-1-i];
            ans = max({ans, pre, suf});
            if(pre == 0)
                pre = 1;
            if(suf == 0)
                suf = 1;
        }
        return ans;
    }
};
