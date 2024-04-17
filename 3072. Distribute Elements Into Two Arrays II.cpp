#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> arr1;
        vector<int> arr2;

        indexed_set st1;
        indexed_set st2;

        st1.insert({nums[0], 0});
        arr1.push_back(nums[0]);
        st2.insert({nums[1], 1});
        arr2.push_back(nums[1]);

        int n = nums.size();
        for(int i=2;i<n;i++){
            int curr = nums[i] + 1;

            int id1 = st1.order_of_key({curr, 0});
            int id2 = st2.order_of_key({curr, 0});

            int size1 = arr1.size() - id1;
            int size2 = arr2.size() - id2;

            if(size1 > size2){
                arr1.push_back(nums[i]);
                st1.insert({nums[i], i});
            }

            else if(size1 < size2){
                arr2.push_back(nums[i]);
                st2.insert({nums[i], i});
            }

            else {
                if(arr1.size() <= arr2.size()){
                    arr1.push_back(nums[i]);
                    st1.insert({nums[i], i});
                }
                else {
                    arr2.push_back(nums[i]);
                    st2.insert({nums[i], i});
                }
            }
        }

        ans = arr1;
        ans.insert(ans.end(), arr2.begin(), arr2.end());
        return ans;
    }
};
