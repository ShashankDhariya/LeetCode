class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;

        for(auto p:piles)
            right = max(right, p);

        long long ans = 0;
        while(left <= right){
            long long mid = left + (right - left)/2;
            long long k = 0;
            for(auto p: piles)
                k += ceil(p/(double)mid);
            
            if(k <= h){
                ans = mid;
                right = mid - 1;
            }

            else 
                left = mid + 1;
        }
        return ans;
    }
};
