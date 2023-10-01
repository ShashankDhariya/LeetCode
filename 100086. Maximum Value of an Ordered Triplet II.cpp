class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        
        int n = nums.size();    
        vector<int> max1(n);
        vector<int> max2(n);
        
        max1[0] = nums[0];
        max2[n-1] = nums[n-1];
        
        for(int i=1;i<n;i++)
            max1[i] = max(max1[i-1], nums[i]);
        
        for(int i=n-2;i>-1;i--)
            max2[i] = max(max2[i+1], nums[i]);
        
        for(int i=1;i<n-1;i++){
            long long a = max1[i-1];
            long long mini = nums[i];
            long long b = max2[i+1];
            ans = max(ans, (a-mini) * b);
        }
        return ans;
    }
};
