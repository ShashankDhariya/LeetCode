class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;

        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++){
            if(manager[i] == -1)    
                continue;
            graph[manager[i]].push_back(i);
        }

        queue<pair<int, int>> q;
        q.push({headID, 0});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto child: graph[curr.first])
                q.push({child, curr.second+informTime[curr.first]});
            ans = max(ans, curr.second);
        }
        return ans;
    }
};
