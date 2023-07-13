class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto p: prerequisites){
            indegree[p[0]]++;
            graph[p[1]].push_back(p[0]);
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto child: graph[curr]){
                indegree[child]--;
                if(indegree[child] == 0)
                    q.push(child);
            }
        }

        for(auto i: indegree){
            if(i > 0)
                return 0;
        }
        return 1;
    }
};
