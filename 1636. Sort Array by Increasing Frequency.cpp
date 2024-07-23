class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto num: nums)
            freq[num]++;

        vector<pair<int, int>> res;
        for(auto f: freq)
            res.push_back({f.second, f.first});
        sort(res.begin(), res.end(), [&](pair<int, int> &a, pair<int, int>& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> ans;
        for(auto r: res){
            for(int i=0;i<r.first;i++)
                ans.push_back(r.second);
        }

        return ans;
    }
};
