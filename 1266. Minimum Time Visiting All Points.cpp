class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0];
        int y = points[0][1];

        int ans = 0;
        int n = points.size();
        for(int i=1;i<n;i++){
            int x1 = abs(points[i][0] - x);
            int y1 = abs(points[i][1] - y);
            ans += min(x1, y1);

            ans += (max(x1, y1) - min(x1, y1));
            x = points[i][0];
            y = points[i][1];
        }

        return ans;
    }
};
