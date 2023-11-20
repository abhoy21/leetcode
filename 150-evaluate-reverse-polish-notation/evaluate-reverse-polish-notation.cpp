class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        int a, b;
        for(string v: tokens){
            if(v == "+"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if(v == "-"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(v == "*"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(v == "/"){
                a = s.top();
                s.pop();
                b = s.top();
                s.pop();
                s.push(b/a);
            }
            else{
                s.push(stoi(v));
            }
        }

        return s.top();
    }
};