class Solution {
public:
    #define ll long long 
    long long maxRunTime(int n, vector<int>& batteries) {
        ll ans = 0;

        ll left = 1;
        ll right = 1e14;
        while(left <= right){
            ll time = left + (right - left) / 2;

            ll avg = 0;
            for(auto b: batteries){
                if(b > time)
                    avg += time;
                else 
                    avg += b;
            }
            avg /= n; 

            if(avg >= time){
                ans = time;
                left = time + 1;
            }
            else 
                right = time - 1;
        }
        return ans;
    }
};
