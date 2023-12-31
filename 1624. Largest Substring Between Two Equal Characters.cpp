class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> res(26, -1);

        int ans = -1;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(res[s[i] - 'a'] == -1)
                res[s[i] - 'a'] = i;

            else 
                ans = max(ans, i - res[s[i] - 'a'] - 1);
        }

        return ans;
    }
};
