class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> ans;

        for(auto num: nums)
            m[num]++;
        
        for(auto num: m){
            if(num.second > n/3)
                ans.push_back(num.first);
        }
        return ans;
    }
};
