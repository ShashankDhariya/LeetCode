class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i=0;i<=n;i++){
            int res = i;
            while(res){
                if(res & 1) ans[i]++;
                res >>= 1;
            }
        }

        return ans;
    }
};
