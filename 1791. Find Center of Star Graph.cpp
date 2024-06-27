class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> path(n+2, 0);

        for(auto edge: edges){
            if(path[edge[0]])
                return edge[0];

            if(path[edge[1]])
                return edge[1];

            path[edge[0]] = 1;
            path[edge[1]] = 1;
        }

        return -1;
    }
};
