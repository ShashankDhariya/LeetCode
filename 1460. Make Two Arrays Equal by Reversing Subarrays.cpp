class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int m = target.size();
        int n = arr.size();

        if(m != n)
            return 0;

        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());

        for(int i=0;i<n;i++){
            if(target[i] != arr[i])
                return 0;
        }

        return 1;
    }
};
