/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:

    int search1(int left, int right, int target, MountainArray &mountainArr){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return 1e5;
    }

    int search2(int left, int right, int target, MountainArray &mountainArr){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mountainArr.get(mid) == target)
                return mid;
            else if(mountainArr.get(mid) > target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return 1e5;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0;
        int right = n-1;
        while(left < right){
            int mid = left + (right - left) / 2;

            if(mountainArr.get(mid) > mountainArr.get(mid+1))
                right = mid;
            else 
                left = mid + 1;
        }
        int peak = left;

        int res1 = search1(0, peak, target, mountainArr);
        int res2 = search2(peak, n-1, target, mountainArr);
        int ans = min(res1, res2);
        return ans == 1e5? -1: ans;
    }
};
