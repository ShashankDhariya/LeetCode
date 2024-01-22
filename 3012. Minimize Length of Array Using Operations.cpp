class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 2;
        
        int mini = *min_element(nums.begin(), nums.end());
        for(auto num: nums){
            freq[num]++;
            if(mini > (num % mini) && (num % mini > 0))
                return 1;
        }
        
        maxFreq = max(maxFreq, freq[mini]);
        return (maxFreq+1) / 2;
    }
};
