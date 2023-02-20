class Solution {
public:

    float length(vector<int>& p1, vector<int>& p2){
        return sqrt(float((p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1])));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) { 
        set<float> s;

        s.insert(length(p1, p2));
        s.insert(length(p1, p3));
        s.insert(length(p1, p4));
        s.insert(length(p2, p3));
        s.insert(length(p2, p4));
        s.insert(length(p3, p4));

        return s.find(0) == s.end() && s.size() == 2;
    }
};
