class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> res;

        int n = names.size();
        for(int i=0;i<n;i++)
            res.push_back({heights[i], names[i]});
        
        sort(res.rbegin(), res.rend());
        vector<string> ans;
        for(auto r: res)
            ans.push_back(r.second);

        return ans;
    }
};
