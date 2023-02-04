class Solution {
public:

    bool comp(vector<int> sMap, vector<int> pMap){
        for(int i=0;i<26;i++){
            if(sMap[i] != pMap[i])
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int m = s.length();
        int n = p.length();

        if(n > m)
            return {};

        vector<int> ans;
        vector<int> sMap(26,0);
        vector<int> pMap(26,0);

        for(int i=0;i<n;i++)
            sMap[s[i] - 'a']++;

        for(int i=0;i<n;i++)
            pMap[p[i] - 'a']++;

        for(int i=n;i<m;i++){
            if(comp(sMap, pMap))
                ans.push_back(i-n);
            sMap[s[i-n] - 'a']--;
            sMap[s[i] - 'a']++;
        }
        if(comp(sMap, pMap))
            ans.push_back(m-n);
        return ans;
    }
};
