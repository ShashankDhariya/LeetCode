class Solution {
public:
    unordered_map<string, bool> mp;
    bool solution(string s1, string s2){
        if(s1 == s2)
            return true;

        if(s1.size() == 1)
            return false;

        string key = s1+s2;
        if(mp.find(key) != mp.end())
            return mp[key];

        int n = s1.size();
        for(int i=1;i<n;++i){
            if((solution(s1.substr(0, i), s2.substr(0, i)) && solution(s1.substr(i), s2.substr(i))) 
             || (solution(s1.substr(0, i), s2.substr(n - i)) && solution(s1.substr(i), s2.substr(0, n - i))))
                return mp[key] = true;
        }
        return mp[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solution(s1, s2);
    }
};
