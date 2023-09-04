class Solution {
public:
    string greatestLetter(string s) {
        vector<int> lowerCase(26, 0);

        int n = s.length();
        for(int i=0;i<n;i++){
            if('a' <= s[i] && s[i] <= 'z')
                lowerCase[s[i] - 'a']++;
        }

        string ans = "";
        for(int i=0;i<n;i++){
            if('a' <= s[i] && s[i] <= 'z')
                continue;

            if(lowerCase[s[i] - 'A'] > 0){
                if(ans == "" || ans[0] - 'A' < s[i] - 'A')
                    ans = s[i];
            }
        }

        return ans; 
    }
};
