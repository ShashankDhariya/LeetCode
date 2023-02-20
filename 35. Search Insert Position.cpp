class Solution {
public:

    int search(int s, int n, vector<int>& nums, int& target){
        int mid = s + (n-s)/2;
        if(nums[mid] == target) 
            return mid;

        if(mid == s){
            if(target < nums[mid])
                return s;
            else
                return n;
        }

        if(target > nums[mid])
            return search(mid, n, nums, target);
        else 
            return search(s, mid, nums, target);
        return mid;
    }

    int searchInsert(vector<int>& nums, int target) {
        return search(0, nums.size(), nums, target);
    }
};
