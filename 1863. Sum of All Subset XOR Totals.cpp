class Solution {
public:

    int solution(int idx, int& n, int x, vector<int>& nums){ 
        if(idx == n)
            return x;

        int taken = solution(idx + 1, n, nums[idx] ^ x, nums);
        int notTaken = solution(idx + 1, n, x, nums);

        return taken + notTaken;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solution(0, n, 0, nums);
    }
};
