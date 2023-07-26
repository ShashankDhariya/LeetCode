class Solution {
public:
    #define ll long long
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int n = dist.size();

        int left = 1;
        int right = 1e7;
        while(left <= right){
            double speed = left + (right - left) / 2;

            double h = 0;
            for(int i=0;i<n;i++){
                if(i == n-1)
                    h += (dist[i] / speed);
                else 
                    h += ceil(dist[i] / speed);
            }

            if(h > hour)
                left = speed + 1;
            else {
                ans = speed;
                right = speed - 1;
            }
        }
        return ans;
    }
};
