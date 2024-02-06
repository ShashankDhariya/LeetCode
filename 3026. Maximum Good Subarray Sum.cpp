class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = -1e18;
        
        long long sum = 0;
        unordered_map<int, long long> mini;
        for(auto num: nums){
            sum += num;
            if(mini.find(num - k) != mini.end())
                ans = max(ans, sum - mini[num-k] + (num - k));
            
            if(mini.find(num + k) != mini.end())
                ans = max(ans, sum - mini[num+k] + (num + k));
            
            if(mini.find(num) == mini.end())
                mini[num] = sum;
            else 
                mini[num] = min(mini[num], sum);
        }
        
        return ans == -1e18? 0: ans;
    }
};
