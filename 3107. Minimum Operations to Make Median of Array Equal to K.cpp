class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int mid = n/2;
        long long ans = abs(nums[mid] - k);
        
        for(int i=mid-1;i>-1;i--){
            if(nums[i] - k > 0)
                ans += (nums[i] - k);
            else 
                break;
        }
                
        for(int i=mid+1;i<n;i++){
            if((k - nums[i]) > 0)
                ans += (k - nums[i]);
            else 
                break;
        }
        
        return ans;
    }
};
