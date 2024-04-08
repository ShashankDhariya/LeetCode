class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0;
        int zero = 0;
        int n = students.size();
        for(int i=0;i<n;i++){
            one += students[i];
            zero += (students[i] == 0? 1: 0);
        }

        int idx = 0;
        while(idx < n){
            if((one == 0 && sandwiches[idx] == 1) || (zero == 0 && sandwiches[idx] == 0))
                return one + zero;

            sandwiches[idx++] == 1? one--: zero--;
        }

        return 0;
    }
};
