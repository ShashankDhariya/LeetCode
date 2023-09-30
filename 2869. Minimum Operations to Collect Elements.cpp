class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_set<int> st;
        for(int i=n-1;i>-1;i--){
            if(nums[i] <= k)
                st.insert(nums[i]);
            if(st.size() == k)
                return n-i;
        }
        
        return n;
    }
};
