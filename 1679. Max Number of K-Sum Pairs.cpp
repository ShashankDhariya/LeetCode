class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;

        unordered_map<int, int> freq;
        for(auto num: nums)
            freq[num]++;

        for(auto num: nums){
            if(freq[num] > 0){
                freq[num]--;
                if(freq[k - num] > 0){
                    freq[k - num]--;
                    ans++;
                }

                else 
                    freq[num]++;
            }
        }

        return ans;
    }
};
