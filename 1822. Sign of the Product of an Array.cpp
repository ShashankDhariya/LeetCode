class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans = 0;
        for(auto num: nums){
            if(!num)
                return 0;
            else if(num < 0)
                ans++;
        }
        return ans%2 == 0? 1:-1;
    }
};
