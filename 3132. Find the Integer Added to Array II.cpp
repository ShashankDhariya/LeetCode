class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int ans = 1e9;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int idx = 0;
                int diff = 1e9;
                bool yes = 1;
                for(int k=0;k<n;k++){
                    if(k == i || k == j)
                        continue;

                    if(diff == 1e9)
                        diff = nums2[idx] - nums1[k];

                    else if(nums2[idx] - nums1[k] != diff){
                        yes = 0;
                        break;
                    }

                    idx++;
                }

                if(yes) 
                    ans = min(ans, diff);
            }
        }

        return ans;
    }
};
