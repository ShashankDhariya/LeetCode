class Solution {
public:
    
    void KMPSearch(string& pat, string& txt, vector<int>& res){
        int M = pat.length();
        int N = txt.length();

        int lps[M];
        computeLPSArray(pat, M, lps);
        int i = 0; 
        int j = 0; 
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                res.push_back(i - j);
                j = lps[j - 1];
            }

            else if (i < N && pat[j] != txt[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
    }

    void computeLPSArray(string& pat, int M, int* lps){
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0) 
                    len = lps[len - 1];

                else 
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        
        vector<int> res1;
        KMPSearch(a, s, res1);
        vector<int> res2;
        KMPSearch(b, s, res2);
        
        set<int> st;
        int size1 = res1.size();
        int size2 = res2.size();
        for(int i=0;i<size1;i++){
            int first = lower_bound(res2.begin(), res2.end(), res1[i]-k) - res2.begin();
            if(first < size2 && abs(res2[first] - res1[i]) <= k){
                st.insert(res1[i]);
                continue;
            }
            
            int second = lower_bound(res2.begin(), res2.end(), res1[i]+k) - res2.begin();
            if(second < size2 && res2[second] > res1[i]+k)
                second--;
            if(second > -1 && second < size2 && abs(res2[second] - res1[i]) <= k){
                st.insert(res1[i]);
                continue;
            }
        }
        
        vector<int> ans;
        for(auto ele: st)
            ans.push_back(ele);
        
        return ans;
    }
};
