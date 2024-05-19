class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if((nums[i] & 1) == (nums[i+1] & 1))
                res.push_back(i);
        }

        int size = res.size();
        vector<bool> ans;
        for(auto query: queries){
            int start = query[0];
            int end = query[1];
            int idx = lower_bound(res.begin(), res.end(), start) - res.begin();
            if(idx < size){
                if(start <= res[idx] && res[idx] + 1 <= end)
                    ans.push_back(0);    
                else 
                    ans.push_back(1);    
            }

            else 
                ans.push_back(1);
        }

        return ans;
    }
};
