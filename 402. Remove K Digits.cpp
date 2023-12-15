class Solution {
public:
    string removeKdigits(string num, int k) {
        string str = "";
        str += num[0];

        int n = num.length();
        for(int i=1;i<n;i++){
            while(k > 0 && !str.empty() && str.back() > num[i]){
                k--;
                str.pop_back();
            }

            str.push_back(num[i]);

            if(str.size() == 1 && str[0] == '0')
                str.pop_back();
        }
        while(k-- && !str.empty())
            str.pop_back();

        return str == ""? "0": str;
    }
};
