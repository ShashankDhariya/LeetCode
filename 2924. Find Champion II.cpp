class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(int i=0;i<edges.size();i++)
            indegree[edges[i][1]]++;
        
        int res = -1;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i] == 0 && res != -1)
                return -1;
            
            if(indegree[i] == 0)
                res = i;
        }
        
        return res;
    }
};
