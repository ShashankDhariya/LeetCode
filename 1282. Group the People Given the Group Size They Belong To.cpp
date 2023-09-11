class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;

        int n = groupSizes.size();
        for(int i=0;i<n;i++)
            mp[groupSizes[i]].push_back(i);

        vector<vector<int>> ans;
        for(auto m: mp){
            vector<int> res(m.first);
            
            int size = m.second.size();
            for(int i=0;i<size;i++){
                res[i % m.first] = m.second[i];
                if(i % m.first == m.first-1)
                    ans.push_back(res);
            }
        }

        return ans;
    }
};
