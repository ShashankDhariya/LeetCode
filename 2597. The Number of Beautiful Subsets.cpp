class Solution {
public:

    int solution(int idx, int& n, int& k, unordered_map<int, int>& res, vector<int>& nums){
        if(idx == n) 
            return 1;
        
        int taken = 0;
        if(!res[nums[idx] - k] && !res[nums[idx] + k]){
            res[nums[idx]]++;
            taken = solution(idx+1, n, k, res, nums);
            res[nums[idx]]--;     
        }

        int notTaken = solution(idx+1, n, k, res, nums);

        return taken + notTaken;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> res;
        return solution(0, n, k, res, nums) - 1;
    }
};
