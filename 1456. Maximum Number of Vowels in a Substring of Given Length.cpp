class Solution {
public:

    bool vowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int maxVowels(string s, int k) {
        int res = 0;
        for(int i=0;i<k;i++){
            if(vowel(s[i]))
                res++;
        }

        int ans = res;
        int n = s.length();
        for(int i=k;i<n;i++){
            if(vowel(s[i])){
                if(!vowel(s[i-k]))
                    res++;
            }
            else {
                if(vowel(s[i-k]))
                    res--;
            }
            ans = max(ans, res);
        }
        return ans;
    }
};
