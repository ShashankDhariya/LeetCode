class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;

        for(auto log: logs) {
            if(log[0] == '.' && log[1] == '.'){
                if(ans > 0)
                    ans--;
            }

            else if(log[0] == '.' && log[1] == '/')
                continue;

            else 
                ans++;
        }

        return ans;
    }
};
