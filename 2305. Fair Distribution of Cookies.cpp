class Solution {
public:
    
    int ans = INT_MAX;
    void check(vector<int>& res){
        int num = INT_MIN;
        for(auto r: res)
            num = max(num, r);
        ans = min(ans, num);
    }

    void solution(int ind, vector<int>& cookies, int k, vector<int>& res){
        if(ind == cookies.size()){
            check(res);
            return;
        }

        for(int i=0;i<k;i++){
            res[i] += cookies[ind];
            solution(ind+1, cookies, k, res);
            res[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> res(k, 0);
        solution(0, cookies, k, res);
        return ans;
    }
};
