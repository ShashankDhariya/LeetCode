class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0;
        int ans = INT_MIN;
        int n = nums.size();
        int zero = 0;
        for(int j=0;j<n;j++){
            if(nums[j] == 0){
                zero++;
                while(zero > k){
                    if(nums[i] == 0)
                        zero--;
                    i++;
                }
            }
            
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
