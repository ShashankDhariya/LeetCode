class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int ctr = 0;
        for(auto ch: s){
            if(ch == 'b')
                ctr++;

            else if(ctr){
                ans++;
                ctr--;
            }
        }

        return ans;
    }
};
