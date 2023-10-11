class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        
        for(auto f: flowers){
            start.push_back(f[0]);
            end.push_back(f[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for(int p: people){
            int numS = upper_bound(start.begin(), start.end(), p) - start.begin();
            int numE = lower_bound(end.begin(), end.end(), p) - end.begin();
            ans.push_back(numS - numE);
        }

        return ans;
    }
};
