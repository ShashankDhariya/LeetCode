class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> freq(26, 0);
        
        for(auto ch: s)
            freq[ch - 'a']++;
        
        int maxFreq = *max_element(freq.begin(), freq.end());
        
        string ans = "";
        int n = s.length();
        for(int i=n-1;i>-1;i--){
            if(freq[s[i] - 'a'] == maxFreq){
                freq[s[i] - 'a'] = 0;
                ans += s[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
