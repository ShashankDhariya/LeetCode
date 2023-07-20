class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(auto a: asteroids){
            if(ans.empty() || a > 0)
                ans.push_back(a);
                
            else {
                if(ans.back() < 0){
                    ans.push_back(a);
                    continue;
                }
                
                while(ans.size()){
                    int prev = ans.back();
                    if(prev < 0){
                        ans.push_back(a);
                        break;
                    }
                    ans.pop_back();

                    if(prev == -a)
                        break;

                    if(prev > -a){
                        ans.push_back(prev);
                        break;
                    }

                    if(ans.empty()){
                        ans.push_back(a);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
