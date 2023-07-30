class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        
        for(auto num: nums)
            st.insert(num);
        
        int u = st.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            st.clear();    
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size() == u)
                    ans++;
            }
        }
        return ans;
    }
};
