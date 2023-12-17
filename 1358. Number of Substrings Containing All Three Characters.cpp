class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;

        int ans = 0;
        int i = 0;
        int n = s.length();
        for(int j=0;j<n;j++){
            freq[s[j]]++;

            while(freq.size() == 3 && i < j){
                ans += (n - j);
                freq[s[i]]--;
                if(freq[s[i]] == 0)
                    freq.erase(s[i]);
                i++;
            }
        }

        return ans;
    }
};
