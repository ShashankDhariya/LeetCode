class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;

        int ans = 1;
        int res = 1;

        sort(nums.begin(), nums.end());
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i])
                continue;

            if(nums[i-1] + 1 == nums[i])
                res++;

            else 
                res = 1;
            
            ans = max(ans, res);
        }

        return ans;
    }
};
