class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        vector<vector<int>> res;
        int n = meetings.size();
        for(int i=0;i<n;i++){
            if(!res.empty() && meetings[i][0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], meetings[i][1]);
            
            else 
                res.push_back(meetings[i]);
        }
        
        int ans = 0;
        for(int i=1;i<res.size();i++)
            ans += (res[i][0] - res[i-1][1] - 1);
        
        ans += (res[0][0] - 1) + (days - res.back()[1]);
        
        return ans;
    }
};
