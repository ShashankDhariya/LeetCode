class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> mp;
        
        for(auto num: nums)
            mp[num]++;
        
        int n = moveFrom.size();
        for(int i=0;i<n;i++){
            if(moveTo[i] == moveFrom[i])
                continue;
            mp[moveTo[i]] += mp[moveFrom[i]];
            mp.erase(moveFrom[i]);
        }
        
        vector<int> ans;
        for(auto m: mp)
            ans.push_back(m.first);   
        
        return ans;
    }
};
