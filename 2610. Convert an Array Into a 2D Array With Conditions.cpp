class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num: nums)
            mp[num]++;

        if(mp.size() == nums.size())
            return {nums};

        vector<vector<int>> ans;
        while(1){
            vector<int> res;
            bool b = 1;
            for(auto& num: mp){
                if(num.second > 0){
                    res.push_back(num.first);
                    num.second--;      
                    b = 0;
                }          
            }
            if(b)
                break;
            ans.push_back(res);
        }
        return ans;
    }
};
