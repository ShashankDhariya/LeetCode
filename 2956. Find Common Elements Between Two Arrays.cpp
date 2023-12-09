class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(2, 0);
            
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        for(auto num: nums1)
            freq1[num]++;
        for(auto num: nums2)
            freq2[num]++;
        
        for(auto num: nums1){
            if(freq2[num])
                ans[0]++;
        }
        
        for(auto num: nums2){
            if(freq1[num])
                ans[1]++;
        }
        
        return ans;
    }
};
