class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        set<pair<int, int>> st;
        
        long long sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert({nums[i], i});
            sum += nums[i];
        }
        
        vector<long long> ans;
        for(auto query: queries){
            int idx = query[0];
            int tim = query[1];
            
            sum -= nums[idx];
            st.erase({nums[idx], idx});
            nums[idx] = 0;
            
            while(tim-- && !st.empty()){
                auto top = *st.begin();
                
                int id = top.second;
                sum -= nums[id];
                nums[id] = 0;
                
                st.erase(top);
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};
