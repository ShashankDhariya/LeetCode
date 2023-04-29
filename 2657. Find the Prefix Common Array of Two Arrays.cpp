class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        unordered_set<int> s;
        
        for(int i=0;i<n;i++){
            int num = 2*(i+1);
            s.insert(A[i]);
            s.insert(B[i]);
            int size = s.size();
            ans[i] = num - size;
        }
        return ans;
    }
};
