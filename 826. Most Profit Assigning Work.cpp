class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> res;
        int n = profit.size();
        for(int i=0;i<n;i++)
            res.push_back({profit[i], difficulty[i]});

        sort(res.rbegin(), res.rend());
        sort(worker.rbegin(), worker.rend());

        int ans = 0;
        int m = worker.size();
        for(int i=0, idx=0;i<m && idx < n;i++){
            while(idx < n && res[idx].second > worker[i])
                idx++;

            ans += idx < n? res[idx].first: 0;
        }

        return ans;
    }
};
