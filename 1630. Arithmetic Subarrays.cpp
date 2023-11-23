class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;

        int size = l.size();
        for(int i=0;i<size;i++){
            int min = *min_element(nums.begin() + l[i], nums.begin() + r[i] + 1);
            int max = *max_element(nums.begin() + l[i], nums.begin() + r[i] + 1);

            int len = r[i] - l[i] + 1;
            int num = (max - min) / (len - 1);
            int j = 0;
            if(min == max)
                ans.push_back(1);

            else if((max - min) % (len - 1))
                ans.push_back(0);

            else {
                vector<bool> n(len);
                for(j=l[i];j<r[i]+1;j++){
                    if((nums[j] - min) % num || n[(nums[j] - min) / num])
                        break;
                    n[(nums[j] - min) / num] = 1;
                }
                ans.push_back(j > r[i]);
            }
        }

        return ans;
    }
};
