class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int res = 0;

        int n = customers.size();
        for(int i=0;i<n;i++){
            if(i - minutes > -1 && grumpy[i - minutes])
                res -= customers[i - minutes];
            
            res += grumpy[i]? customers[i]: 0;
            ans = max(ans, res);
        }

        for(int i=0;i<n;i++)
            ans += grumpy[i]? 0: customers[i];

        return ans;
    }
};
