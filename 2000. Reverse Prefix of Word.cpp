class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = word;

        int idx = 0;
        int n = word.length();
        for(idx=0;idx<n;idx++){
            if(word[idx] == ch) 
                break;
        }

        reverse(ans.begin(), ans.begin() + idx + 1);
        return idx == n? word: ans;
    }
};
