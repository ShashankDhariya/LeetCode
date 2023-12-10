class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        
        int n = batteryPercentages.size();
        for(int i=0;i<n;i++){
            if(batteryPercentages[i] - ans > 0)
                ans++;
        }
        
        return ans;
    }
};
