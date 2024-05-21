class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(128);
        vector<bool> used(128);
        string ans = "";
        for(auto c: s)
            cnt[c]++;
        
        for(auto c: s){
            cnt[c]--;
            if(used[c])
                continue;
            while(!ans.empty() && ans.back() > c && cnt[ans.back()] > 0){
                used[ans.back()] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            used[c] = true;
        }

        return ans;
    }
};