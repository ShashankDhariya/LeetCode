class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        
        int res1 = 1;
        int side = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1)
                side++;
            
            else 
                side = 1;
            res1 = max(res1, side);
        }
        
        side = 1;
        int res2 = 1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i] - vBars[i-1] == 1)
                side++;
            
            else 
                side = 1;
            res2 = max(res2, side);
        }
        
        int ans = min(res1, res2) + 1;
        return ans*ans;
    }
};
