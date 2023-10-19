class Solution {
public:
    int minSteps(int n) {
        int ans = 0;

        vector<int> res(n+1, 0);
        res[1] = 0;
        for(int i=2;i<=n;i++)
            res[i] = i;

        for(int i=3;i<=n;i++){
            int j = i+i;
            int add = 2;
            while(j <= n){
                res[j] = min(res[j], res[i] + add);
                j += i;
                add++;
            }
        }
        
        return res[n];
    }
};
