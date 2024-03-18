class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string, bool> mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=i;j<n;j++){
                str += s[j];
                if((j - i) > 0)
                    mp[str] = 1;
            }
        }

        reverse(s.begin(), s.end());
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=i;j<n;j++){
                str += s[j];
                if(mp[str])
                    return 1;
            }
        }
        
        return 0;
    }
};
