class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> freq;
        
        int n = word.length();
        for(int i=0;i<n;i+=k){
            int j = i;
            string str = "";
            for(j=0;j<k;j++)
                str += word[i+j];
            
            freq[str]++;
        }
        
        int ans = 1e9;
        for(auto f: freq)
            ans = min(ans, n/k - f.second);
        
        return ans;
    }
};
