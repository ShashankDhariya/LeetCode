class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, nums[0]);
        vector<int> suff(n, nums[n-1]);
        
        for(int i=1;i<n;i++){
            if(nums[i] < pre[i-1])
                pre[i] = nums[i];
            else
                pre[i] = pre[i-1];
        }
        
        for(int i=n-2;i>-1;i--){
            if(nums[i] < suff[i+1])
                suff[i] = nums[i];
            else
                suff[i] = suff[i+1];
        }
        
        int ans = INT_MAX;
        for(int i=1;i<n-1;i++){
            if(pre[i-1] < nums[i] && nums[i] > suff[i+1])
                ans = min(ans, pre[i-1] + nums[i] + suff[i+1]);
        }
        
        return ans == INT_MAX? -1: ans;
    }
};
