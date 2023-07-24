class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int ans = 1;
        for(int j=1;j<n;j++){
            if(nums[j] - nums[i] <= (k+k))
                ans = max(ans, j-i+1);
            else 
                i++;
        }
        
        return ans;
    }
};
