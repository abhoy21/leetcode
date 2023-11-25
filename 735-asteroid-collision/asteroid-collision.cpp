class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> s;
        int n = asteroids.size();
        
        for (int i : asteroids) {
            
            
            while(!s.empty() && s.top()>0 && i<0)
            {
                int sum = i+s.top();
                if(sum<0)
                {
                 s.pop();   
                }else if(sum>0)
                {
                    i = 0;
                    break;
                }else{
                    i=0;
                    s.pop();
                    break;
                }
            }

            if(i!=0) {
                s.push(i);
            }
        }

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};