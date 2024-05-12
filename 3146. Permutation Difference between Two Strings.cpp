class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> idx(26, 0);

        int n = s.length();
        for(int i=0;i<n;i++)
            idx[s[i] - 'a'] = i;

        int ans = 0;
        for(int i=0;i<n;i++)
            ans += abs(i - idx[t[i] - 'a']);

        return ans;
    }
};
