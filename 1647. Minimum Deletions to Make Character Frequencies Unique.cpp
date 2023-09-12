class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(auto str: s)   
            freq[str - 'a']++;

        unordered_map<int, int> avail;
        for(auto f: freq)  
            avail[f]++;

        int maxi = *max_element(freq.begin(), freq.end());
        
        int del = 0;
        for(int i=maxi;i>0;i--){
            if(avail[i] > 1){
                del += avail[i] - 1;
                avail[i-1] += avail[i] - 1;
            }
        }
        
        return del;
    }
};
