#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans = "";

        for (auto it : num) {
            while (!st.empty() && k > 0 && st.top() > it) {
                st.pop();
                k--;
            }
            st.push(it);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        int nonZeroIndex = 0;
        while (nonZeroIndex < ans.size() && ans[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        ans = ans.substr(nonZeroIndex);
        
        if (ans.empty()) return "0";
        return ans;
    }
};
