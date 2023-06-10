#define ll long long
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int lSide = index;
        int rSide = n - index - 1;
        ll ans = 0;

        int left = 1;
        int right = maxSum;

        while(left <= right){
            int mid = left + (right - left)/2;

            ll lSum = 0;
            ll rSum = 0;
            ll ele = mid - 1;

            if(rSide <= ele)
                rSum = (ele*(ele+1))/2 - ((ele - rSide)*(ele - rSide + 1))/2;
            else 
                rSum = (ele*(ele+1))/2 + (rSide - ele);

            if(lSide <= ele)
                lSum = (ele*(ele+1))/2 - ((ele - lSide)*(ele - lSide + 1))/2;
            else 
                lSum = (ele*(ele+1))/2 + (lSide - ele);

            ll sum = lSum + mid + rSum;
            if(sum <= maxSum){
                left = mid + 1;
                ans = mid;
            }
            else 
                right = mid - 1;
        }
        return ans;
    }
};
