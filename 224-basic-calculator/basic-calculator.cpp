class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int sum = 0;
        int sign = 1;
        
        for(int i=0;i<s.size();i++){
            if(s[i]==' ')    continue;
            if(s[i]=='('){
                stk.push(sum);
                stk.push(sign);
                sum = 0;
                sign = 1;
            }else if(s[i]==')'){
                sum *= stk.top(); stk.pop();
                sum += stk.top(); stk.pop();
            }else if(s[i]=='+'){
                sign = 1;
            }else if(s[i]=='-'){
                sign = -1;
            }else{
                string temp;
                int j = i;      
                while(j<s.size() && s[j]>='0' && s[j]<='9'){
                    temp += s[j++];
                }
                i = j - 1;
                sum+= sign*(stoi(temp));
            }
        }

        return sum;
    }
};