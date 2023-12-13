class Solution {
public:
    static bool strCompare(string a, string b){
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto i : nums)
            str.push_back(to_string(i));
        sort(str.begin(), str.end(), strCompare);
        string ans;
        for(int i = 0; i < str.size(); i++)
            ans += str[i];
        
        return ans[0] == '0'? "0" : ans; 
    }
};