class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int idx = 0;
        int count = 0;
        
        int maxi = *max_element(nums.begin(), nums.end());
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == maxi)
                count++;
            
            while(count >= k){
                if(nums[idx] == maxi && count == k)
                    break;
                
                if(nums[idx] == maxi)
                    count--;
                idx++;
            }
                
            if(count == k)
                ans += idx + 1;
        }
        
        return ans;
    }
};
