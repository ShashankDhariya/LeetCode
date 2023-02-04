class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        if(m > n)
            return false;

        sort(s1.begin(), s1.end());
        for(int i=0;i<n-m+1;i++){
            string s = s2.substr(i, m);
            sort(s.begin(), s.end());
            if(s1 == s)
                return true;
        }
        return false;
    }
};
