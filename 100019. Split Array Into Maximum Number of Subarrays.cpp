class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int ans = 0;
        
        int res = nums[0];
        
        int n = nums.size();
        for(int i=1;i<n;i++)
            res &= nums[i];
        
        if(res > 0)
            return 1;
        
        int a = -1;
        for(int i=0;i<n;i++){
            if(a == -1)
                a = nums[i];
            else
                a &= nums[i];
            
            if(a == 0){
                a = -1;
                ans++;
            }
        }
        
        return ans;
    }
};
