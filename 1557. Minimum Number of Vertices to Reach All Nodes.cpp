class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        unordered_set<int> s;

        for(auto edge: edges)
            s.insert(edge[1]);

        for(int i=0;i<n;i++){
            if(s.find(i) == s.end())
                ans.push_back(i);
        }
        return ans;
    }
};  
