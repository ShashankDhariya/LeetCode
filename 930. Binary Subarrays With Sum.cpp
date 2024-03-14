class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=1;i<=n;i++)
            prefix[i] = nums[i-1] + prefix[i-1];

        int ans = 0;
        unordered_map<int, int> freq;
        freq[0]++;
        for(int i=1;i<=n;i++){     
            int idx = (prefix[i] - goal);
            if(idx > -1)
                ans += freq[idx];

            freq[prefix[i]]++;
        }

        return ans;
    }
};
