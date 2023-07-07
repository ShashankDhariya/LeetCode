class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for(auto c: s)
            mp[c]++;
        
        int ans = 0;
        bool b = 0;
        for(auto m: mp){
            if(m.second % 2 == 0)
                ans += m.second;
            else{
                ans += m.second - 1;
                b = 1;
            }
        }
        int odd = b? 1: 0;
        return ans + odd;
    }
};
