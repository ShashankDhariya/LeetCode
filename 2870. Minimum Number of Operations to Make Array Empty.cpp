class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num: nums)
            freq[num]++;

        int ans = 0;
        for(auto f: freq){
            if(f.second == 1)
                return -1;

            if(f.second % 3 == 0)
                ans += (f.second / 3);

            else 
                ans += ((f.second / 3) + 1); 
        }
        
        return ans;
    }
};
