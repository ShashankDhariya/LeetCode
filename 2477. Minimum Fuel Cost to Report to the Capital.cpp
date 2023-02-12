class Solution {
public:

    int dfs(int curr, int prev, vector<vector<int>>& tree, int& seats, long long& ans){
        int people = 1;
        for(auto num: tree[curr]){
            if(num == prev)
                continue;
            people += dfs(num, curr, tree, seats, ans);
        }
        if(curr != 0)
            ans += (people + seats - 1) /seats;
        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long ans = 0;
        vector<vector<int>> tree(roads.size() + 1);

        for(int i=0;i<roads.size();i++){
            tree[roads[i][0]].push_back(roads[i][1]);
            tree[roads[i][1]].push_back(roads[i][0]);
        }

        dfs(0, -1, tree, seats, ans);
        return ans;
    }
};
