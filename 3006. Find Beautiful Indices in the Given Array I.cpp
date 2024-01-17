class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        
        vector<int> res1;
        int n1 = a.length();
        for(int i=0;i<n-n1+1;i++){
            if(s.substr(i, n1) == a)
                res1.push_back(i);
        }
        
        vector<int> res2;
        int n2 = b.length();
        for(int i=0;i<n-n2+1;i++){
            if(s.substr(i, n2) == b)
                res2.push_back(i);
        }
        
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
