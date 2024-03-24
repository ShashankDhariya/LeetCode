class Solution {
public:
    int minOperations(int k) {
        int ans = 1e9;
        for(int i=1;i<k;i++){
            int times = ceil(k / (double)i);
            ans = min(ans, i + times - 2);
        }
        
        return ans == 1e9? 0: ans;
    }
};
