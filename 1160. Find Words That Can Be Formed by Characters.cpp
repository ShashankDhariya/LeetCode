class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freqCh(26, 0);
        for(auto ch: chars)
            freqCh[ch - 'a']++;

        int ans = 0;
        for(auto word: words){
            bool b = 1;
            vector<int> freqW(26, 0);
            for(auto ch: word){
                freqW[ch - 'a']++;
                if(freqW[ch - 'a'] > freqCh[ch - 'a']){
                    b = 0;
                    break;
                }
            }
            if(b)   ans += word.size();
        }

        return ans;
    }
};
