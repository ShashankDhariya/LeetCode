class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1;
        int res = 0;
        for(auto num: nums){
            res += num;
            if(res < 0)
                ans = max(ans, abs(res)+1);
        }
        return ans;
    }
};
