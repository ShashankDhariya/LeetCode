class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int ans = 0;
        int n = points.size();
        for(int i=1;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=0;j<i;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(x2 > x1 || y2 < y1)
                    continue;
                
                bool yes = 1;
                for(int k=j+1;k<i;k++){
                    int xd = points[k][0];
                    int yd = points[k][1];
                    
                    if((xd >= x2 && xd <= x1) && (yd >= y1 && yd <= y2)){
                        yes = 0;
                        break;
                    }
                }
                
                if(yes)
                    ans++;
            }
        }
        
        return ans;
    }
};
