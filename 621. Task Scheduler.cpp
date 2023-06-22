class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto task: tasks)
            freq[task - 'A']++;

        sort(freq.rbegin(), freq.rend());

        int ans = (freq[0] - 1) * n;
        for(int i=1;i<freq.size();i++){
            ans -= min(freq[0] - 1, freq[i]);
        }
        return max(0, ans) + tasks.size();
    }
};
