class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> freq(1001, 0);
        for(auto num: nums1)
            freq[num] = 1;

        vector<int> ans;
        for(auto num: nums2){
            if(freq[num]) {
                freq[num] = 0;
                ans.push_back(num);
            }
        }

        return ans;
    }
};
