class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};

        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 1)
                q.push(i);
        }

        while(n > 2){
            int size = q.size();
            n -= size;
            for(int i=0;i<size;i++){
                int curr = q.front();
                q.pop();

                for(auto child: graph[curr]){
                    indegree[child]--;
                    if(indegree[child] == 1)
                        q.push(child);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
