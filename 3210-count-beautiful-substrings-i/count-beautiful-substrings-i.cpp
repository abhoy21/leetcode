class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++){
            int vowels = 0, cons = 0;
            for(int j = i; j < s.length(); j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    vowels++;
                else
                    cons++;
                if(vowels == cons && (vowels * cons) % k == 0){
                    ans++;
                }
            } 
        }
        return ans;
    }
};