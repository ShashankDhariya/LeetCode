class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, -1);
        queue<pair<int, int>> q;
        int dist = 0;

        vector<vector<pair<int, int>>> graph(n);
        for(auto num: redEdges)
            graph[num[0]].push_back({num[1], 0});
        for(auto num: blueEdges)
            graph[num[0]].push_back({num[1], 1});

        q.push({0, -1});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto curr = q.front();
                q.pop();
                if(ans[curr.first] == -1)
                    ans[curr.first] = dist;
                for(auto &num: graph[curr.first]){
                    if(curr.second != num.second && num.first != -1){
                        q.push(num);
                        num.first = -1;
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};
