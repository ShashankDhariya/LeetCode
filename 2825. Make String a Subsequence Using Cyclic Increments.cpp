class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        unordered_map<char, set<int>> mp;
        
        int n1 = str1.length();
        for(int i=0;i<n1;i++)
            mp[str1[i]].insert(i);
        
        int curr = -1;
        int n2 = str2.length();
        for(int i=0;i<n2;i++){
            char prev;
            if(str2[i] == 'a')
                prev = 'z';
            else 
                prev = str2[i] - 1;
            
            int idx1 = -1;
            int idx2 = -1;
            
            if(mp.find(str2[i]) != mp.end()){
                auto idx = mp[str2[i]].upper_bound(curr);
                if(idx != mp[str2[i]].end())
                    idx1 = *idx;
            }
            
            if(mp.find(prev) != mp.end()){
                auto idx = mp[prev].upper_bound(curr);
                if(idx != mp[prev].end())
                    idx2 = *idx;
            }
            
            if(idx1 == -1 && idx2 == -1)
                return 0;
            
            if(idx1 != -1 && idx2 != -1)
                curr = min(idx1, idx2);
            else if(idx1 == -1)
                curr = idx2;
            else 
                curr = idx1;
        }
        return 1;
    }
};
