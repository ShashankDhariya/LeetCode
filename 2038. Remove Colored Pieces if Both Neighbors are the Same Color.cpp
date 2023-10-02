class Solution {
public:

    int moves(string colors, char take, char noTake){
        int res = -1;
        int i = 0;
        int n = colors.size();

        int ans = 0;
        for(int j=0;j<n;j++){
            while(i < j && colors[i] != take)
                i++;

            if(colors[j] == noTake){
                res = j - i - 2;
                ans += res > 0? res: 0;
                i = j;
            }

            else if(j == n-1){
                res = j - i - 1;
                ans += (res > 0)? res: 0;
            }
        }

        return ans;
    }

    bool winnerOfGame(string colors) {
        int alice = moves(colors, 'A', 'B');
        int bob = moves(colors, 'B', 'A');

        return alice > bob;
    }
};
