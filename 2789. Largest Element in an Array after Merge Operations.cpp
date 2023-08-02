class Solution {
public:
    #define ll long long
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        
        ll ans = nums[n-1];
        ll res = nums[n-1];
        for(int i=n-2;i>-1;i--){
            if(res >= nums[i])
                res += nums[i];
            
            else 
                res = nums[i];
            ans = max(ans, res);
        }
        return ans;
    }
};
