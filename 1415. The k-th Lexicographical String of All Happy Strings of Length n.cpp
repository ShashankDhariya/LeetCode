class Solution {
public:

    void makeString(bool a, bool b, bool c, string str, int n, int& iter, string& ans){
        if(iter == 0)
            return;

        if(n == 0){
            iter--;
            ans = str;
            return;
        }
        if(a)   makeString(0, 1, 1, str+'a', n-1, iter, ans);
        if(b)   makeString(1, 0, 1, str+'b', n-1, iter, ans);
        if(c)   makeString(1, 1, 0, str+'c', n-1, iter, ans);
    }

    string getHappyString(int n, int k) {
        string ans;
        int iter = k;
        makeString(1, 1, 1, "", n, iter, ans);
        return !iter? ans : "";
    }
};
