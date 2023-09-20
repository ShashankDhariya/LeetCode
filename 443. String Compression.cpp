class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();
        int i = 0;
        while(i < n){
            int j = i+1;
            int ctr = 1;
            while(j < n && chars[i] == chars[j]){
                j++;
                ctr++;
            }

            if(ctr == 1)
                chars[idx++] = chars[i];

            else {
                string str = to_string(ctr);
                chars[idx++] = chars[i];
                for(int a=0;a<str.size();a++)
                    chars[idx++] = str[a];
            }
            i = j;
        }

        return idx;
    }
};
