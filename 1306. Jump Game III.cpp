class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pair<int, int>> q;

        int n = arr.size();
        vector<bool> vis(n, false);
        q.push({start, arr[start]});
        vis[start] = true;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.second == 0)
                return true;

            int a = curr.first + curr.second;
            if(a < n && !vis[a]){
                q.push({a, arr[a]});
                vis[a] = true;
            }

            int b = curr.first - curr.second;
            if(b > -1 && !vis[b]){
                q.push({b, arr[b]});
                vis[b] = true;
            }
        }
        return false;
    }
};
