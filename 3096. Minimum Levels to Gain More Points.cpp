class Solution {
public:
    int minimumLevels(vector<int>& possible) {
        int n = possible.size();
        vector<int> pref(n);
        pref[0] = (possible[0] == 1? 1: -1);
        
        for(int i=1;i<n;i++)
            pref[i] = pref[i-1] + (possible[i] == 1? 1: -1);
        
        vector<int> suff(n);
        suff[n-1] = (possible[n-1] == 1? 1: -1);
        for(int i=n-2;i>-1;i--)
            suff[i] = suff[i+1] + (possible[i] == 1? 1: -1);
        
        for(int i=0;i<n-1;i++){
            if(pref[i] > suff[i+1])
                return i+1;
        }
        
        return -1;
    }
};
