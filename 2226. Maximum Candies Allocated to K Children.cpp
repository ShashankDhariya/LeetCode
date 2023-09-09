class Solution {
public:
    #define ll long long
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int ans = 0;

        ll low = 1;
        ll high = 1e7;
        while(low <= high){
            ll children = k;
            ll mid = low + (high - low) / 2;

            for(int i=0;i<n;i++){
                if(children <= 0)
                    break;
                children -= candies[i] / mid;
            }

            if(children <= 0){
                ans = mid;
                low = mid+1;
            }
            else 
                high = mid-1;
        }

        return ans;
    }
};
