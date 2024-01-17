class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0;
        unordered_map<int, int> freq;
        for(auto num: nums){
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }
    
        int ans = 0;
        for(auto f: freq)
            ans += maxFreq == f.second? f.second: 0; 
        
        return ans;
    }
};
