class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        int n = nums.size();
        
        int i = 0;
        unordered_map<int, int> mp;
        long long sum = 0;
        for(int j=0;j<n;j++){
            mp[nums[j]]++;
            sum += nums[j];
            
            if(j-k >= 0){
                mp[nums[j-k]]--;
                if(mp[nums[j-k]] == 0)  mp.erase(nums[j-k]);
                
                sum -= nums[i++];
            }
            
            if(j >= k-1 && mp.size() >= m)  
                ans = max(ans, sum);
        }
        
        return ans;
    }
};
