class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool yes = 1;
                
                if(words[i].size() > words[j].size())
                    continue;
                
                string pre = "";
                for(int k=0;k<words[i].size();k++){
                    if(words[i][k] != words[j][k]){
                        yes = 0;
                        break;
                    }
                    pre += words[i][k];
                }
                if(!yes)
                    continue;
                
                string suff = "";
                int a = words[i].size() - 1;
                int b = words[j].size() - 1;
                while(a > -1 && b > -1){
                    if(words[i][a] != words[j][b]){
                        yes = 0;
                        break;
                    }
                    suff += words[i][a];
                    a--;
                    b--;
                }
                
                if(!yes)
                    continue;
                
                reverse(suff.begin(), suff.end());
                if(pre == suff )
                    ans++;
            }
        }
        
        return ans;
    }
};
