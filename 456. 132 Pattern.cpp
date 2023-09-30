class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;

        int c = INT_MIN;
        int n = nums.size();
        for(int i=n-1;i>-1;i--){
            if(nums[i] < c)
                return 1;

            while(!st.empty() && nums[i] > st.top()){
                c = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }

        return 0;
    }
};
