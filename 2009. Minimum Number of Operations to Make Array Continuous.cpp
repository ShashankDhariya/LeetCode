class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = INT_MAX;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int idx = 1;
        for(int i=1;i<n;i++){
            if(nums[i] != nums[i-1])
                nums[idx++] = nums[i];
        }

        for(int i=0, j=0;i<idx;i++){
            while(j < idx && nums[j] < nums[i] + n){
                j++;
                ans = min(ans, n - (j - i));
            }
        }

        return ans;
    }
};
