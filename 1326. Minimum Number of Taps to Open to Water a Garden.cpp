class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int ans = 0;

        vector<pair<int, int>> intervals;
        for(int i=0;i<=n;i++){
            int start = i - ranges[i];
            int end = i + ranges[i];
            if(start < end) intervals.push_back({start, end});
        }

        sort(intervals.begin(), intervals.end(), [](pair<int, int>& a, pair<int, int>& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        int i = 0;
        int end = 0;
        while(i < intervals.size()){
            int j = i;
            int res = 0;
            while(j < intervals.size() && intervals[j].first <= end){
                res = max(res, intervals[j].second);
                j++;
            }
            if(i == j)  break;
            i = j;
            end = res;
            ans++;

            if(end >= n)
                return ans;
        }

        return -1;
    }
};
