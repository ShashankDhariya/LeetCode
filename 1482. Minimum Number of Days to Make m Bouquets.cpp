class Solution {
public:

    bool check(int val, vector<int>& bloomDay, int& n, int m, int& k){
        for(int i=0;i<n;i){
            bool yes = 1;
            for(int j=0;j<k;j++){
                if(i == n || bloomDay[i++] > val){
                    yes = 0;
                    break;
                }
            }

            if(yes) m--;
        }

        return m < 1;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans = -1;
        int left = 1;
        int right = 1e9;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(check(mid, bloomDay, n, m, k)){
                ans = mid;
                right = mid - 1;
            }

            else 
                left = mid + 1;
        }

        return ans;
    }
};
