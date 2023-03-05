class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> freq;
        queue<vector<int>> q;

        for(int i=0;i<n;i++)
            freq[arr[i]].push_back(i);

        q.push({arr[n-1], n-1, 0});
        vector<bool> vis(n, false);

        while(!q.empty()){
            int size = q.size();
            auto curr = q.front();
            q.pop();

            if(curr[1] == 0)
                return curr[2];

            vis[curr[1]] = true;
            if(curr[1]+1 < n && !vis[curr[1]+1]) 
                q.push({arr[curr[1]+1], curr[1]+1, curr[2]+1});

            if(curr[1]-1 > -1 && !vis[curr[1]-1]) 
                q.push({arr[curr[1]-1], curr[1]-1, curr[2]+1});

            for(auto num:freq[curr[0]]){
                if(!vis[num])
                    q.push({arr[num], num, curr[2]+1});
            }   
            freq[curr[0]].clear();
        }
        return 0;
    }
};
