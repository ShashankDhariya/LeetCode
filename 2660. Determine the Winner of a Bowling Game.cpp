class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        int ans1 = 0;
        int ans2 = 0;
        
        for(int i=0;i<n;i++){
            if(i-2 > -1 && player1[i-2] == 10)
                    ans1 += player1[i]*2;
            else if(i-1 > -1 && player1[i-1] == 10)
                    ans1 += player1[i]*2;
            else 
                ans1 += player1[i];
        }
        
        for(int i=0;i<n;i++){
            if(i-2 > -1 && player2[i-2] == 10)
                    ans2 += player2[i]*2;            
            else if(i-1 > -1 && player2[i-1] == 10)
                    ans2 += player2[i]*2;            
            else
                ans2 += player2[i];
        }
        
        if(ans1 > ans2)
            return 1;
        if(ans1 < ans2)
            return 2;
        return 0;
    }
};
