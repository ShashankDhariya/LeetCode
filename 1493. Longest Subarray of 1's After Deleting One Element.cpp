class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;

        int n = nums.size();
        int i = 0;
        int j = 0;
        int zero = -1;

        while(i < n && j < n){
            if(nums[j] == 0){
                if(zero != -1){
                    ans = max(ans, j - i - 1);
                    i = zero + 1;
                    zero = j;
                }
                else 
                    zero = j;
            }
            j++;
        }
        ans = max(ans , j - i - 1);
        return ans;
    }
};
