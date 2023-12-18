class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi = -1;
        int sMax = -1;
        int mini = 1e5;
        int sMin = 1e5;

        for(auto num: nums){
            if(num > maxi){
                sMax = maxi;
                maxi = num;
            }

            else if(num > sMax)
                sMax = num;

            if(num < mini){
                sMin = mini;
                mini = num;
            }

            else if(num < sMin)
                sMin = num;
        }

        return maxi*sMax - mini*sMin;
    }
};
