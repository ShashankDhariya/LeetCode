class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        int time = customers[0][0];

        int n = customers.size();
        for(int i=0;i<n;i++){
            if(time < customers[i][0]) {
                wait += customers[i][1];
                time = customers[i][0];
            }

            else
                wait += (time - customers[i][0]) + customers[i][1];
                
            time += customers[i][1];
        }

        return wait / n;
    }
};
