class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        stack<int> numStack; // Keep track of multipliers

        string k = "";
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    k += s[i];
                    i++;
                }
                numStack.push(stoi(k));
                k = "";
                i--; // Move the index back one step to handle the character after the number
            }
            else if (s[i] == '[') {
                stk.push('[');
            }
            else if (s[i] == ']') {
                string substring = "";
                while (!stk.empty() && stk.top() != '[') {
                    substring = stk.top() + substring;
                    stk.pop();
                }
                stk.pop(); // Remove '[' from the stack
                
                int multiplier = numStack.top();
                numStack.pop();

                string repeatedSubstring = "";
                for (int j = 0; j < multiplier; j++) {
                    repeatedSubstring += substring;
                }

                // Push the repeated substring back onto the stack
                for (char c : repeatedSubstring) {
                    stk.push(c);
                }
            }
            else {
                stk.push(s[i]);
            }
        }

        // Construct the final answer by popping from the stack
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};
