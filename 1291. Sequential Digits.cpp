class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";

        vector<int> ans;
        for(int i=0;i<9;i++){
            string str = "";
            for(int j=i;j<9;j++){
                str += s[j];

                int num = stoi(str);
                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};
