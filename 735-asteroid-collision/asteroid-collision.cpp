class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n = asteroids.size();
        for(int i = 0;i < n;i++){
            int num = asteroids[i];
            if(st.empty() || num > 0)
                st.push(num);
            else if(st.top() < 0)
                st.push(num);
            else{
                while(!st.empty()){
                    int a = st.top();
                    if(st.top() < 0){
                        st.push(num);
                        break;
                    }
                    else if(st.top() > abs(num))
                        break;
                    else if(st.top() == abs(num)){
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        if(st.empty()){
                            st.push(num);
                            break;
                        }
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int low = 0;
        int high = ans.size()-1;
        while(low < high){
            int temp = ans[low];
            ans[low++] = ans[high];
            ans[high--] = temp;
        }
        return ans;
    }
};