class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0;

        unordered_map<int, long long> mp;
        mp[0] = 1;
        int freq = 0;
        int n = word.length();
        for(auto w: word){
            freq ^= (1 << (w - 'a'));
            ans += mp[freq];

            for(char ch='a';ch<='j';ch++){
                int oddPattern = freq ^ (1 << (ch - 'a'));
                ans += mp[oddPattern];
            }

            mp[freq]++;
        }

        return ans;
    }
};
