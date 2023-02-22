class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element;
        int ctr = 0;

        for(auto num: nums){
            if(!ctr)
                element = num;

            if(element == num)
                ctr++;
            else 
                ctr--;
        }
        return element;
    }
};
