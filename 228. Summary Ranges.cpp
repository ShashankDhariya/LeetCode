class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;

        string str = "";
        for(int i=0;i<n;i++){
            if(i == n-1){
                str += to_string(nums[i]);
                ans.push_back(str);
            }
            else if(nums[i] != nums[i+1] - 1){
                if(str == "")
                    str = to_string(nums[i]);
                else 
                    str += to_string(nums[i]);
                ans.push_back(str);
                str = "";
            }
            else if(str == "")
                str = to_string(nums[i]) + "->";
        }
        return ans;
    }
};
