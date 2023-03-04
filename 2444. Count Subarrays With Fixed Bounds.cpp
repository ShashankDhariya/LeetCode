class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int maxi = -1;
        int mini = -1;
        int leftBound = -1;

        for(int i=0;i<n;i++){
            if(nums[i] >= minK && nums[i] <= maxK){
                maxi = (nums[i] == maxK)? i: maxi;
                mini = (nums[i] == minK)? i: mini;
                ans += max(0, min(maxi, mini) - leftBound);
            }

            else{
                leftBound = i;
                mini = -1;
                maxi = -1;
            }
        }
        return ans;
    }
};
