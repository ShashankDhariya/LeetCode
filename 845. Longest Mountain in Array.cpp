class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        if(n < 3)
            return ans;

        int left = arr[0] < arr[1]? 0: -1;
        for(int i=1;i<n;i++){
            int right = (i+1 < n)? arr[i+1]: 1e4;
            
            if(arr[i-1] > arr[i] && arr[i] <= right){
                if(left != -1)
                    ans = max(ans, i - left + 1);
                left = i;
            }
            
            else if(arr[i] < arr[i-1] && i-1 == left)
                left = i;

            else if(arr[i] == arr[i-1] ||  arr[i] == right)
                left = i;
        }

        return ans > 2? ans: 0;
    }
};
