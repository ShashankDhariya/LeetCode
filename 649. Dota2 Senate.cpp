class Solution {
public:
    string predictPartyVictory(string senate) {
      int n = senate.length();
        queue<int> R;
        queue<int> D;

        for(int i=0;i<n;i++)
          senate[i] == 'R'? R.push(i): D.push(i);

        while(!R.empty() && !D.empty()){
          int r = R.front();
          int d = D.front();  
          R.pop();
          D.pop();
          r < d? R.push(r + n): D.push(r + n);
        }
        return R.empty()? "Dire": "Radiant";
    }
};
