class Solution {
public:

    int atmost(vector<int>& nums, int k){
        int ans = 0;
        int ctr = 0;
        int i = 0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            ctr += (nums[j] % 2);

            while(i <= j && ctr > k)
                ctr -= (nums[i++] % 2);
            
            ans += (j - i + 1);
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};
