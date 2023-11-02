class Solution {
public:
    void func(string digits, map<char, string>& hsh, string temp, vector<string>& ans, int index) {
        if (index == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string str = hsh[digits[index]];
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            func(digits, hsh, temp, ans, index + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0) return ans;
        map<char, string> hsh;
        hsh['2'] = "abc";
        hsh['3'] = "def";
        hsh['4'] = "ghi";
        hsh['5'] = "jkl";
        hsh['6'] = "mno";
        hsh['7'] = "pqrs";
        hsh['8'] = "tuv";
        hsh['9'] = "wxyz";
        string temp = "";

        func(digits, hsh, temp, ans, 0);

        return ans;
    }
};