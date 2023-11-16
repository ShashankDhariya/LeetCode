class Solution {
public:

    string res = "";
    void solution(int idx, string ans, unordered_map<string , bool>& freq){
        if(res != "")
            return;
            
        if(idx == -1){
            if(freq[ans] == 0)
                res = ans;
            return;
        }

        ans[idx] = '1';
        solution(idx-1, ans, freq);
        ans[idx] = '0';
        solution(idx-1, ans, freq);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string , bool> freq;
        for(auto num: nums)
            freq[num] = 1;
        
        string ans = "";
        int n = nums.size();
        for(int i=0;i<n;i++)
            ans += '0';

        solution(n-1, ans, freq);

        return res;
    }
};
