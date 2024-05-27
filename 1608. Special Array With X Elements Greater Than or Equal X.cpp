class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = -1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(n - i <= nums[i]){
                if(i-1 == -1 || n - i > nums[i-1])
                    ans = n - i;
            }
        }

        return ans;
    }
};
