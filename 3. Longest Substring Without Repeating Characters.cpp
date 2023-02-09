class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int ans = 0;
        int n = str.length();
        unordered_map<char, int> m;
        int i=0;
        int j=0;

        for(j=0;j<n;j++){
            m[str[j]]++;
            if(m.size() == j-i+1)
                ans = max(ans, j-i+1);
            
            else {
                m[str[i]]--;
                if(m[str[i]] == 0)
                    m.erase(str[i]);
                i++;
            }
        }
        return ans;
    }
};
