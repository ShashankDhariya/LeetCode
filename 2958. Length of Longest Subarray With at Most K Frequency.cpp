class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = -1;
        unordered_map<int, int> freq;
        int i = 0;
        int n = nums.size();
        for(int j=0;j<n;j++){
            freq[nums[j]]++;
            while(i < j && freq[nums[j]] > k){
                freq[nums[i]]--;
                i++;
                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
            }
            
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};
