class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int n = min({s1.length(), s2.length(), s3.length()});

        int i = 0;
        while(i < n && s1[i] == s2[i] && s2[i] == s3[i])
            i++;

        return i == 0? -1: s1.length() + s2.length() + s3.length() - i * 3;
    }
};
