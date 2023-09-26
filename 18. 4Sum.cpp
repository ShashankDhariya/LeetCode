class Solution {
public:
    #define ll long long
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i != 0 && nums[i] == nums[i-1])
                continue;

            for(int j=i+1;j<n;j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;

                int a = nums[i];
                int b = nums[j];
                int c = j+1;
                int d = n-1;
                while(c < d){
                    if(((ll)a + (ll)b + (ll)nums[c] + (ll)nums[d]) == target){
                        ans.push_back({a, b, nums[c], nums[d]});
                        while(c < d && nums[c] == nums[c+1])
                            c++;
                        c++;
                        while(c < d && nums[d] == nums[d-1])
                            d--;
                        d--;
                    }

                    else if(((ll)a + (ll)b + (ll)nums[c] + (ll)nums[d]) < target)
                        c++;

                    else 
                        d--;
                }
            }
        }

        return ans;
    }
};
