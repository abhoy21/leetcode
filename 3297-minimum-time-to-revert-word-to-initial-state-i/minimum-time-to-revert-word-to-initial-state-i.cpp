class Solution {
public:
    bool isEqual(string &word, string &target){
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(target[i] != '*' && target[i] != word[i])
                return false;
        }

        return true;
    }
    int minimumTimeToInitialState(string word, int k) {
        string copy = word;
        int cnt = 0;

        do{
            copy = copy.substr(k) + string(k, '*');
            cnt++;
        }while(!isEqual(word, copy));

        return cnt;
    }
};