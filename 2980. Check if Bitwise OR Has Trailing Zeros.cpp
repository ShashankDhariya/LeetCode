class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = 0;
        for(auto num: nums) {
            if(!(num & 1))
                even++;
        }
        
        return (even > 1);
    }
};
