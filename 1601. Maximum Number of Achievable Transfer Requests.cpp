class Solution {
public:
    bool check(vector<int>& res){
        for(auto r: res){
            if(r != 0)
                return 0;
        }
        return 1;
    }

    void solution(int i, vector<vector<int>>& requests, vector<int>& res, int ctr, int& ans) {
        if(i == requests.size()){
            if(check(res))
                ans = max(ans, ctr);
            return ;
        }

        solution(i+1, requests, res, ctr, ans);

        res[requests[i][0]]--;
        res[requests[i][1]]++;
        solution(i+1, requests, res, ctr+1, ans);
        res[requests[i][0]]++;
        res[requests[i][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> res(n, 0);
        solution(0, requests, res, 0, ans);
        return ans;
    }
};
