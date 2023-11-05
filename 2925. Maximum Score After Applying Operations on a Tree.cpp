class Solution {
public:
    #define ll long long
    ll solution(int curr, int par, vector<vector<int>>& tree, vector<int>& values){
        if(tree[curr].size() == 1 && curr != 0)
            return values[curr];
        
        ll ans = 0;
        for(auto child: tree[curr]){
            if(child != par)
                ans += solution(child, curr, tree, values);
        }
        
        return min(ans, (ll)values[curr]);
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> tree(n);
        for(auto e: edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }
        
        ll sum = 0;
        for(auto v: values)
            sum += v;

        return sum - solution(0, 0, tree, values);
    }
};
