class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int, bool> mp;
        
        int rep = -1;
        int acSum = 0;
        for(auto g: grid){
            for(auto ele: g){
                if(mp[ele]){
                    rep = ele;
                    continue;
                }
                else
                    mp[ele] = 1;
                acSum += ele;
            }
        }
        
        int n = grid.size();
        n *= n;
        int exSum = (n * (n+1)) / 2;
        
        int mis = exSum - acSum;
        
        return {rep, mis};
    }
};
