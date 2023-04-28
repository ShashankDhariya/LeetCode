class Solution {
public:

    bool isSimilar(string a, string b){
        int n = a.length();
        int ctr = 0;
        for(int i=0;i<n;i++){
            if(a[i] != b[i])
                ctr++;
        }
        if(ctr == 0 || ctr == 2)
            return true;
        return false;
    }

    void dfs(int i, int& n, vector<string>& strs, vector<bool>& vis){
        vis[i] = 1;
        for(int j=0;j<n;j++){
            if(vis[j])
                continue;
            if(isSimilar(strs[i], strs[j]))  
                dfs(j, n, strs, vis);
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int ans = 0;
        vector<bool> vis(n, 0);

        for(int i=0;i<n;i++){
            if(vis[i])
                continue;
            dfs(i, n, strs, vis);
            ans++;
        }
        return ans;
    }
};
