class Solution {
public:
    #define ll long long
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        ll left = 1;
        ll right = 1e14;

        while(left <= right){
            ll mid = left + (right-left)/2;
            ll trips = 0;
            
            for(int i=0;i<n;i++)
                trips += (mid / time[i]);
            
            if(trips < totalTrips)
                left = mid + 1;

            else
                right = mid - 1;
        }
        return left;
    }
};
