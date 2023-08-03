class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int ans = 0;
        
        while(1){
            if(mainTank >= 5){
                mainTank -= 5;
                ans += 50;
                if(additionalTank > 0){
                    mainTank++;
                    additionalTank--;
                }
            }
            else {
                ans += mainTank * 10;
                break;
            }
        }
        return ans;
    }
};
