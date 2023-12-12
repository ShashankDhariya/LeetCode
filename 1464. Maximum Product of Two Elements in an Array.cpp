class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max = -1;
        int sMax = -1;

        for(auto num: nums){
            if(num >= max){
                sMax = max;
                max = num;
            }
            else if(num > sMax)
                sMax = num;
        }

        return (max - 1) * (sMax - 1);
    }
};
