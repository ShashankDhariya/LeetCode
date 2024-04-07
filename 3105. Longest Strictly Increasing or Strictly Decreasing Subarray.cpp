class Solution {
public:
    
    int solution(vector<int>& nums){
        int ans = 1;
        int res = 1;
        int prev = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > prev)
                res++;
            
            else 
                res = 1;
            
            prev = nums[i];
            ans = max(ans, res);
        }
        
        return ans;
    }
    
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = solution(nums);
        reverse(nums.begin(), nums.end());
        int dec = solution(nums);
        
        return max(inc, dec);
    }
};
