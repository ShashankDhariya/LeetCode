class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> dp(26, -1);
        
        int n = word.size();
        for(int i=0;i<n;i++){
            if(word[i] > 91)
                dp[word[i] - 'a'] = i;
        }
        
        vector<int> res(26, 0);
        for(int i=0;i<n;i++){
            if(word[i] < 91){
                if(dp[word[i] + 32 - 'a'] == -1 || res[word[i] - 'A'] == 1 || res[word[i] - 'A'] == -1)
                    continue;
                
                if(dp[word[i] + 32 - 'a'] < i)
                    res[word[i] - 'A'] = 1;
                
                else if(dp[word[i] + 32 - 'a'] > i)
                    res[word[i] - 'A'] = -1;
            }
        }
        
        int ans = 0;
        for(auto r: res)
            ans += (r == 1? 1: 0);
        
        return ans;
    }
};
