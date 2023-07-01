class Solution {
public:
    string reverseWords(string s) {
        string ans;
        vector<string> a;
        string t;
        for (char i : s) {
            if (i != ' ') {
                t += i;
            } else {
                if (!t.empty()) {
                    a.push_back(t);
                    t.clear();
                }
            }
        }

        if (!t.empty()) {
            a.push_back(t);
        }

        for (int i = a.size() - 1; i >= 0; i--) {
            ans += a[i];
            ans += ' ';
        }

        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};