class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            
            vector<int> freq(26, 0);
            for(int j=i;j<n;j++){
                freq[s[j] - 'a']++;
                
                if(*max_element(freq.begin(), freq.end()) < 3)
                    ans = max(ans, j-i+1);
            }
        }
        
        return ans;
    }
};
