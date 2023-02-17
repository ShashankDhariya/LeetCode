class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        string str = s;
        int ans = 0;

        while(1){
            bool b = false;
            s = str;
            for(int i=0;i<n-1;i++){
                if(s[i] == '0' && s[i+1] == '1'){
                    str[i] = '1';
                    str[i+1] = '0';
                    b = true;
                }
            }
            if(!b)
                break;
            ans++;
        }
        return ans;
    }
};
