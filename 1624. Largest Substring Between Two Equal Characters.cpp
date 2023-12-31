class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<pair<int, int>> res(26, pair<int, int> (-1, -1));

        int n = s.length();
        for(int i=0;i<n;i++){
            if(res[s[i] - 'a'].first == -1)
                res[s[i] - 'a'].first = i;

            else 
                res[s[i] - 'a'].second = i;
        }

        int ans = -1;
        for(int i=0;i<26;i++){
            if(res[i].second == -1)
                continue;
            ans = max(ans, res[i].second - res[i].first - 1);
        }

        return ans;
    }
};
