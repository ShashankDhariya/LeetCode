class Solution {
public:
    #define ll long long
    vector<int> singleNumber(vector<int>& nums) {
        ll x = 0;
        for(auto num: nums)
            x ^= num;
        
        ll rsb = x & -x;

        ll x1 = 0;
        ll x2 = 0;
        for(auto num: nums){
            if(rsb & num)
                x1 ^= num;
            else 
                x2 ^= num;
        }

        return {(int)x1, (int)x2};
    }
};
