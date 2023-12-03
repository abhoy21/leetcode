class Solution {
public:
    void func(string digits,map<char, string>& hsh, vector<string>& ans, string temp, int idx){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }

        string s = hsh[digits[idx]];

        for(int i = 0; i < s.size(); i++){
            temp.push_back(s[i]);
            func(digits, hsh, ans, temp, idx+1);
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

        func(digits, hsh, ans, temp, 0);

        return ans;
    }
};