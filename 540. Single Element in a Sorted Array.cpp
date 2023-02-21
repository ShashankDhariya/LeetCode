class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size();

        for(int i=0;i<n;i++)
            m[nums[i]]++;

        for(auto num: m){
            if(num.second == 1)
                return num.first;
        }
        return -1;
    }
};
