class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans = 0;
        
        unordered_set<int> st;
        for(int i=1;;i++){
            if(st.size() == n)
                return ans;
            
            else if(st.find(target - i) != st.end())
                continue;
            
            else {
                ans += i;
                st.insert(i);
            }
        }
        return ans;
    }
};
