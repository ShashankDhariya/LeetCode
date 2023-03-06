class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        int i = 0;
        while(k){
            ans++;
            if(i < n && ans == arr[i])
                i++;
            else
                k--;
        }
        return ans;
    }
};
