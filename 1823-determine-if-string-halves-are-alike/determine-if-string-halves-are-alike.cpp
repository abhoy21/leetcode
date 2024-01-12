class Solution {
public:
    int func(string s) {
        int cnt = 0;
        for(char ch : s){
            ch = tolower(ch);
            cnt += ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
         }

        return cnt;

    }
    bool halvesAreAlike(string s) {
        return func(s.substr(0, s.length()/ 2)) == func(s.substr(s.length()/2));
        
    }
};