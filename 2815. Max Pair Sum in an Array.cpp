class Solution {
public:
    
    bool maxDigit(int a, int b){
        int res1 = -1;
        while(a){
            res1 = max(res1, a%10);
            a /= 10;
        }
        
        int res2 = -1;
        while(b){
            res2 = max(res2, b%10);
            b /= 10;
        }
        return res1 == res2;
    }
    
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(maxDigit(nums[i], nums[j]))
                    ans = max(ans, nums[i]+nums[j]);
            }
        }
        
        return ans;
    }
};
