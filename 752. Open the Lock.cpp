class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool> dead;
        for(auto d: deadends)
            dead[d] = 1;

        if(dead["0000"])
            return -1;

        unordered_map<string, bool> vis;
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        vis["0000"] = 1;

        while(!q.empty()){
            string curr = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(curr == target)
                return steps;

            for(int idx=0;idx<4;idx++){
                char cw = (((curr[idx] - '0') + 1) % 10) + '0';
                char acw = ((((curr[idx] - '0') - 1) + 10) % 10) + '0';

                string str = curr;
                str[idx] = cw;
                if(!vis[str] && !dead[str]) {
                    q.push({str, steps+1});
                    vis[str] = 1;
                }
                
                str[idx] = acw;
                if(!vis[str] && !dead[str]) {
                    q.push({str, steps+1});
                    vis[str] = 1;
                }
            }
        }

        return -1;
    }
};
