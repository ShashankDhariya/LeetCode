class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    void dfs(string source, vector<string>& ans){
        auto& to_list = graph[source];
        while(!to_list.empty()){
            string dest = to_list.top();
            to_list.pop();
            dfs(dest, ans);
        }
        ans.push_back(source);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto str: tickets)
            graph[str[0]].push(str[1]);
    
        vector<string> ans;
        dfs("JFK", ans);
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
