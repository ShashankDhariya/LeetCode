class Solution {
public:
    int minimumChairs(string s) {
        int ans = 0;
        int res = 0;
        for(auto ch: s){
            ch == 'E'? res++: res--;
            ans = max(ans, res);
        }
        
        return ans;
    }
};
