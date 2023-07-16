int dp[1 << 16][64];
bool choice[1 << 16][64];
class Solution {
public:

    int req_mask;
    int m;
    int solution(int i, int mask, vector<int>& p){
        if(mask == req_mask)
            return 0;

        if(i == m)
            return 10000;

        if(dp[mask][i] != -1)
            return dp[mask][i];

        int take = 1 + solution(i+1, mask | p[i], p);
        int noTake = solution(i+1, mask, p);

        if(take < noTake)
            choice[mask][i] = 1;

        return dp[mask][i] = min(take, noTake);
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size();
        m = people.size();

        unordered_map<string, int> skills;
        for(int i=0;i<n;i++)
            skills[req_skills[i]] = i;

        vector<int> p;
        for(auto& num: people){
            int h = 0;
            for(auto a: num)
                h |= 1 << skills[a];
            p.push_back(h);
        }
        req_mask = (1 << n) - 1;

        memset(dp, -1, 1 << n + 8);
        memset(choice, 0, 1 << n + 6);
        solution(0, 0, p);

        vector<int> ans;
        for(int i=0, mask=0;i<m;i++){
            if(choice[mask][i]){
                ans.push_back(i);
                mask |= p[i];
            }
            if(mask == req_mask)
                break;
        }
        return ans;
    }
};
