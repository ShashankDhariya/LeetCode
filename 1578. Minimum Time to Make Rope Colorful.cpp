class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;

        int i = 0;
        int n = colors.length();
        while(i < n){
            int time = -1;
            int sum = 0;
            int j = i;
            while(j < n && colors[j] == colors[i]){
                sum += neededTime[j];
                time =  max(time, neededTime[j]);
                j++;
            }

            if(j - i > 1)
                ans +=  (sum-time);
            
            i = j;
        }

        return ans;
    }
};
