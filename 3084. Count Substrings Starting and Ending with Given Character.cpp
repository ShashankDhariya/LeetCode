class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long ans = 0;
        
        int prev = 1;
        for(auto ch: s){
            if(ch == c){
                ans += prev;
                prev++;
            }
        }
        
        return ans;
    }
};
