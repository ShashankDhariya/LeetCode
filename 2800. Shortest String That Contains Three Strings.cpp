class Solution {
public:
    
    static bool comp(pair<int, string>& a, pair<int, string>& b){
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    
    string solution(string a, string b, string c) {
        string str = a;
        
        bool bo = 1;
        int n = str.length();
        for(int i=0;i<n;i++){
            if(str == b){
                bo = 0;
                break;
            }
            int s = min((int)b.size(), n-i);
            if(str.substr(i, s) == b.substr(0, s)){
                bo = 0;
                str += b.substr(s);
                break;
            }
        }
        if(bo)
            str += b;
        
        bo = 1;
        n = str.length();
        for(int i=0;i<n;i++){
            if(str == c){
                bo = 0;
                break;
            }
            int s = min((int)c.size(), n-i);
            if(str.substr(i, s) == c.substr(0, s)){
                bo = 0;
                str += c.substr(s);
                break;
            }
        }
        if(bo)
            str += c;
        return str; 
    }
    
    string minimumString(string a, string b, string c) {
        vector<pair<int, string>> s(6);
        s[0] = {1, solution(a, b, c)};
        s[1] = {1, solution(a, c, b)};
        s[2] = {1, solution(b, a, c)};
        s[3] = {1, solution(b, c, a)};
        s[4] = {1, solution(c, b, a)};
        s[5] = {1, solution(c, a, b)};
        
        for(int i=0;i<6;i++)
            s[i].first = s[i].second.length();
    
        sort(s.begin(), s.end(), comp);
        
        return s[0].second;
    }
};
