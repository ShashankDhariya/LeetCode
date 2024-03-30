class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = 1e5;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = 0;
            for(int j=i;j<n;j++){
                x |= nums[j];
                if(x >= k)
                    ans = min(ans, j-i+1);
            }
        }
        
        return ans == 1e5? -1: ans;
    }
};
