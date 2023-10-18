class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto r: relations){
            graph[r[0] - 1].push_back(r[1] - 1);
            indegree[r[1] - 1]++;
        }

        queue<int> q;
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
                ans[i] = time[i];
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto child: graph[curr]){
                indegree[child]--;
                ans[child] = max(ans[child], ans[curr] + time[child]);
                if(indegree[child] == 0)
                    q.push(child);
            }
        }

        int idx = max_element(ans.begin(), ans.end()) - ans.begin();
        return ans[idx];
    }
};
