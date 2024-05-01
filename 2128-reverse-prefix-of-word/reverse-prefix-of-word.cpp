class Solution {
public:
    string reverseStr(string temp, int l, int r) {
        while (l <= r) {
            swap(temp[l], temp[r]);
            l++;
            r--;
        }
        return temp;
    }
    string reversePrefix(string word, char ch) {
        int ind = 0;
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                ind = i;
                break;
            }
        }
        string ans = "";
        if(ind != 0){
            ans = reverseStr(word.substr(0, ind+1), 0, ind);
            ans += word.substr(ind+1);
        }
        else{
            ans = word;
        }

        return ans;
    }
};