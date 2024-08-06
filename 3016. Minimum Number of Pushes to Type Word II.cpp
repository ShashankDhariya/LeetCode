class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto ch: word)
            freq[ch - 'a']++;
        
        sort(freq.rbegin(), freq.rend());

        int ans = 0;
        vector<int> res(26, 0);
        for(int i=0;i<26;i++){
            if(freq[i] == 0)
                break;

            res[i] = ((i + 8) / 8);
        }

        for(int i=0;i<26;i++)
            ans += freq[i] * res[i];

        return ans;
    }
};
