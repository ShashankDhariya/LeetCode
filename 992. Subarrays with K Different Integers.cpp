class Solution {
public:

    int atMost(vector<int>& nums, int k){
        int ans = 0;
        int i = 0;
        unordered_map<int, int> freq;

        int n = nums.size();
        for(int j=0;j<n;j++){
            freq[nums[j]]++;

            while(i <= j && freq.size() > k) {
                freq[nums[i]]--;
                if(freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                
                i++;
            }

            ans += (j - i + 1);
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};
