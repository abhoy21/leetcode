class Solution {
public:
    int func(int i, vector<string> &arr, string &ans){
        unordered_set<char>s(ans.begin(), ans.end());
        if(ans.size() != s.size())
            return 0;
        if(i >= arr.size())
            return ans.size();
        int maxlength = ans.size();
        for(auto c : arr[i])
            ans.push_back(c);
        maxlength = max(maxlength, func(i+1, arr, ans));
        for(auto c : arr[i])
            ans.pop_back();
        maxlength = max(maxlength, func(i+1,arr, ans));

        return maxlength;
    }
    int maxLength(vector<string>& arr) {
        string ans = "";
        return func(0, arr, ans);
    }
};