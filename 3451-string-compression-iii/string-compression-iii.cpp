class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        int cnt = 1;
        for(int i= 1; i< word.size(); i++, cnt++){
            if(word[i] == word[i-1] && cnt < 9)
                continue;
            ans += to_string(cnt) + word[i-1];
            cnt = 0;
        }
        ans += to_string(cnt) + word.back();

        return ans;
    }
};