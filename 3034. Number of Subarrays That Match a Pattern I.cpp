class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        
        int ans = 0;
        for(int i=0;i<n-m;i++){
            bool yes = 1;
            for(int j=i+1;j<i+m+1;j++){
                if(nums[j] > nums[j-1] && pattern[j-i-1] != 1){
                    yes = 0;
                    break;        
                }
                else if(nums[j] == nums[j-1] && pattern[j-i-1] != 0){
                    yes = 0;
                    break;        
                }
                else if(nums[j] < nums[j-1] && pattern[j-i-1] != -1){
                    yes = 0;
                    break;        
                }
            }
            if(yes)
                ans++;
        }
        
        return ans;
    }
};
