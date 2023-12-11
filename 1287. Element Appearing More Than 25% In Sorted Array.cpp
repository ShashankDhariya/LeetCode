class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int idx = 0.25 * n;

        for(int i=idx;i<n;i++){
            if(arr[i] == arr[i-idx])
                return arr[i];
        }

        return -1;
    }
};
