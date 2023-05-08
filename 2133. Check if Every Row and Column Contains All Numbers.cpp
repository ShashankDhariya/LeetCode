class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=0;j<n;j++){
                s.insert(matrix[i][j]);
                if(s.size() == j)
                    return false;
            }
        }

        for(int i=0;i<n;i++){
            unordered_set<int> s;
            for(int j=0;j<n;j++){
                s.insert(matrix[j][i]);
                if(s.size() == j)
                    return false;
            }
        }
        return true;
    }
};
