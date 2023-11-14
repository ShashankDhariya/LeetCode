class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<int> freqF(26, 1e5);
        vector<int> freqB(26, 1e5);
        for(int i=0;i<n;i++){
            freqF[s[i] - 'a'] = min(freqF[s[i] - 'a'], i);
            freqB[s[i] - 'a'] = i;
        }
            
        int ans = 0;
        for(int i=0;i<26;i++){
            if(freqF[i] == 1e5 || freqB[i] == 1e5)
                continue;

            unordered_set<int> st;
            for(int j=freqF[i]+1;j<freqB[i];j++)
                st.insert(s[j]);
            ans += st.size();
        }

        return ans;
    }
};
