class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> ans(n, 1);

        for(int i=1;i<n;i++){
            if(ratings[i-1] < ratings[i])
                ans[i] = ans[i-1] + 1;
        }

        for(int i=n-2;i>-1;i--){
            if(ratings[i] > ratings[i+1]){
                if(ans[i] <= ans[i+1])
                    ans[i] = ans[i+1] + 1;
            }
        }

        int res = 0;
        for(auto a: ans)
            res += a;

        return res;
    }
};
