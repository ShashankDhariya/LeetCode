class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0;
        int negCount = 0;
        int prevZero = -1;
        int prevNeg = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                if(prevNeg == -1)
                    prevNeg = i;
                negCount++;
            }

            if(nums[i] == 0){
                prevZero = i;
                negCount = 0;
                prevNeg = -1;
                continue;
            }

            if(negCount % 2 == 0)
                ans = max(ans, i-prevZero);
            else 
                ans = max(ans, i-prevNeg);
        }
        return ans;
    }
};
