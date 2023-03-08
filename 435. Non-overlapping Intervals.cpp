class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        pair<int, int> res;

        sort(intervals.begin(), intervals.end(), comp);
        res = {intervals[0][0], intervals[0][1]};
        
        for(int i=1;i<n;i++){
            if(res.second > intervals[i][0])
                ans++;
            else 
                res = {intervals[i][0], intervals[i][1]};
        }
        return ans;
    }
};
