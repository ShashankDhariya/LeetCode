class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0;
        int sum2 = 0;

        for(int i=0;i<t.length();i++){
            if(i <= s.length())
            sum1 += s[i];
            sum2 += t[i];
        }

        return (char)(sum2 - sum1);
    }
};

/*
    OR - Using xor operator
class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        
        for(auto c: s)
            ans ^= c;

        for(auto c: t)
            ans ^= c;

        return (char)ans;
    }
};

  OR - Using Map (Brute Force)
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int, int> m;
        for(int i=0;i<t.size();i++){
            if(i == s.length())
                m[t[i]]++;
            else {
                m[s[i]]++;
                m[t[i]]++;
            }
        }

        for(auto num: m){
            if(num.second % 2 != 0)
                return num.first;
        }
        return ' ';
    }
};
*/
