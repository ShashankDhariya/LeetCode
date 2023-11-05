class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int res = 0;

        int ans = arr[0];
        int n = arr.size();
        for(int i=1;i<n;i++){
            if(arr[i] < ans)
                res++;
        
            else {
                res = 1;
                ans = max(ans, arr[i]);
            }
                
            if(res == k)
                return ans;
        }

        return ans;
    }
};
