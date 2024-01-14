class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int len = 0;
        
        for(auto d: dimensions){
            int length = d[0]*d[0] + d[1]*d[1];
            if(length > len){
                ans = d[0]*d[1];
                len = length;
            }
            
            else if(length == len)
                ans = max(ans, d[0]*d[1]);
        }
        
        return ans;
    }
};
