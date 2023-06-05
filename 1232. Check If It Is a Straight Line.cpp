class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        sort(coordinates.begin(), coordinates.end());

        int x = coordinates[1][0] - coordinates[0][0];
        int y = coordinates[1][1] - coordinates[0][1];
        double m = y/(double)x;

        for(int i=1;i<n;i++){
            int a = coordinates[i][0] - coordinates[i-1][0];
            int b = coordinates[i][1] - coordinates[i-1][1];
            if(b / (double)a != m)
                return 0;
        }
        return 1;
    }
};
