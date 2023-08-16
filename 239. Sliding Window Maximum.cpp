// Using Deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() == i-k)
                dq.pop_front();

            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            dq.push_back(i);
            if(i >= k-1)    ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};

OR

// Using hashmap
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        map<int, int> freq;
        for(int i=0;i<k;i++)
            freq[nums[i]]++;
        ans.push_back(freq.rbegin()->first);

        for(int i=k;i<n;i++){
            freq[nums[i]]++;
            freq[nums[i - k]]--;
            if(freq[nums[i-k]] == 0)
                freq.erase(nums[i-k]);
            ans.push_back(freq.rbegin()->first);
        }
        return ans;
    }
};
