class Solution {
public:

    bool isPossible(int& maxW, vector<int>& weights, int& days){
        int sum = 0;
        int d = 1;
        for(auto w: weights){
            sum += w;
            
            if(sum > maxW){
                d++;
                sum = w;
            }
        }
        return d <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxW = INT_MIN;
        int sum = 0;

        for(auto num: weights){
            sum += num;
            maxW = max(maxW, num);
        }

        int low = maxW;
        int high = sum;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low) / 2;
            if(isPossible(mid, weights, days)){
                high = mid - 1;
                ans = mid;
            }
            else 
                low = mid + 1;
        }
        return ans;
    }
};
