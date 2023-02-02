class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<int, int> m;

        int ind = 0;
        for(auto o: order)
            m[o] = ind++;

        for(int i=1;i<words.size();i++){
            if(words[i] == words[i-1])
                continue;

            string str1 = words[i-1];
            string str2 = words[i];
            int n = str1.length();
            int k = str2.length(); 
            bool b = false;

            int j = 0;
            while(j < n && j < k){
                if(m[str1[j]] > m[str2[j]])
                    return false;
                
                else if(m[str1[j]] == m[str2[j]])
                    j++;

                else if(m[str1[j]] < m[str2[j]]){
                    b = true;
                    break;
                }
            }
            if(j < n && !b)
                return false;
        }
        return true;
    }
};
