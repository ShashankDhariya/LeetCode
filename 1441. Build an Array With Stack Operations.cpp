class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;

        int curr = 1;
        int size = target.size();
        for(int i=0;i<size;i++){
            while(curr < target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                curr++;
            }

            ans.push_back("Push");
            curr++;
        }

        return ans;
    }
};
