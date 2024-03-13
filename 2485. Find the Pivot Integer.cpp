class Solution {
public:
    int pivotInteger(int n) {
        int left = 1;
        int right = n;

        int sum = (n * (n+1)) / 2;
        while(left <= right){
            int pivot = left + (right - left) / 2;

            int prefix = (pivot * (pivot+1)) / 2;
            int suffix = sum - prefix + pivot;

            if(prefix == suffix)
                return pivot;

            else if(prefix < suffix)
                left = pivot + 1;

            else 
                right = pivot - 1;
        }

        return -1;
    }
};
