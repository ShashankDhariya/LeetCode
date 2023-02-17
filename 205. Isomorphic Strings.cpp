class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.length();
        int n1 = t.length();
        if(n1 != n)
            return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for(int i=0;i<n;i++){
            if(m1[s[i]] == 0)
                m1[s[i]] = t[i];

            else if(m1[s[i]] != t[i])
                return false;

            if(m2[t[i]] == 0)
                m2[t[i]] = s[i];

            else if(m2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
