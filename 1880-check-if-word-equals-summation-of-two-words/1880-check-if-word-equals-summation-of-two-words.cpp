class Solution {
    int stringtonum(string str)
    {
        int ans = 0;
        for(auto v: str)
        {
            int letter = v - 'a';
            ans = ans * 10 + letter;
        }
        
        return ans;
    }
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        if(stringtonum(firstWord) + stringtonum(secondWord) == stringtonum(targetWord))
            return 1;
        else
            return 0;
        
    }
};