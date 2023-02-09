class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long ans = 0;
        int n = ideas.size();
        vector<set<string>> res(26);

        for(auto str:ideas)
            res[str[0] - 'a'].insert(str.substr(1));

        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                int common = 0;
                for(auto str: res[i]){
                    if(res[j].count(str))
                        common++;
                }
                ans += ((res[i].size() - common) * (res[j].size() - common));
            }
        }
        return 2*ans;
    }
};
