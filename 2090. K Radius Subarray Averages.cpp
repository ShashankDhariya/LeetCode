#define ll long long
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n , -1);

        int ele = k + k;
        ll num = 0;
        for(int i=0;i<n;i++){
            if(i == ele)
                break;
            num += nums[i];
        }

        ele++;
        for(int i=k;i<n-k;i++){
            num += nums[i+k];
            ans[i] = num / ele;
            num -= nums[i-k];
        }
        return ans;
    }
};
