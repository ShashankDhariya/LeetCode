class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int s = 0;
        
        for(int i=0;i<n;i++){
            if(nums[i] == 0)
                ans += (++s);
            else 
                s = 0;
        }
        return ans;
    }
};
