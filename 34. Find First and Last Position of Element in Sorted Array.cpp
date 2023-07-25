// O(n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = -1;
        int b = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == target && a == -1)
                a = i;
            if(nums[i] == target)
                b = i;
        }
        return {a,b};
    }
};

// O(log n)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return {-1, -1};
        
        int first = 0;
        int last = 0;

        int left = 0;
        int right = n-1;
        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[mid] < target)
                left = mid + 1;
            else 
                right = mid;
        }
        first = left;

        left = 0;
        right = n-1;
        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] <= target){
                last = mid;
                left = mid+1;
            }
            else 
                right = mid-1;
        }

        if(nums[first] != target || nums[last] != target)
            return {-1,-1};
        
        return {first, last};
    }
};
