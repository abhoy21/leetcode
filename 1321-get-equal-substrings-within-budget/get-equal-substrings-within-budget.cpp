class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, cost = 0;
        int maxlength = 0;
        for(int j = 0; j < s.size(); j++){
            cost += abs(int(s[j]) - int(t[j]));
            if(cost > maxCost){
                cost -= abs(int(s[i]) - int(t[i]));
                i++;
            }
            maxlength = max(maxlength, j - i + 1);
        }

        return maxlength;
    }
};