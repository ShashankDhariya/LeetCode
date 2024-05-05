class Solution {
public:
    int minAnagramLength(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        
        for(auto ch: s)
            freq[ch - 'a']++;
        
        sort(freq.rbegin(), freq.rend());
        
        int ans = freq[0];
        for(auto f: freq){
            if(f == 0)
                break;
            
            ans = __gcd(ans, f);
        }
        
        return n / ans;
    }
};
