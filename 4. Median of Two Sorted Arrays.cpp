class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;

        int index = -1;
        int n = nums1.size();
        int m = nums2.size();
        int res;
        int ans;

        int stop = (m+n) / 2;
        while(i < n || j < m){
            if(i >= n)
                res = nums2[j++];

            else if(j >= m)
                res = nums1[i++];

            else {
                if(nums1[i] < nums2[j])
                    res = nums1[i++];
                else 
                    res = nums2[j++];
            }
            index++;
            if(index == stop)
                break;
            else if(index == stop - 1)
                ans = res;
        }
        
        if((m+n) % 2 != 0)
            return (double)res;

        return (double)(ans+res)/2;
    }
};
