class Solution {
public:
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if(s[start++] != s[end--])
                return false;
        }

        return true;
    }
    void func(string s, vector<string>& v, vector<vector<string>>& ans, int idx){
        if(idx == s.size()){
            ans.push_back(v);
            return;
        }

        for(int i = idx; i < s.size(); i++){
            if(isPalindrome(s, idx, i)){
                v.push_back(s.substr(idx, i-idx+1));
                func(s, v, ans, i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;

        func(s, v, ans, 0);

        return ans;
    }
};