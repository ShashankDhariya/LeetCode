class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = INT_MIN;
        
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long res = (nums[i] - nums[j]) * (long long)nums[k];
                    ans = max(ans, res);
                }
            }
        }
        
        return ans < 0? 0: ans;
    }
};
