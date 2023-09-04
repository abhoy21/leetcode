class Solution {
public:
    int minimumOperations(string num) {
        bool isfive = false;
        bool iszero = false;
        for(int i = num.size(); i >= 0; i--)
        {
            if(iszero && num[i] == '0') return num.size()-2-i;
            if(iszero && num[i] == '5') return num.size()-2-i;
            if(isfive && num[i] == '7') return num.size()-2-i;
            if(isfive && num[i] == '2') return num.size()-2-i;
            if(num[i] == '5') isfive = true;
            if(num[i] == '0') iszero = true;
        }
        if(iszero) return num.size() - 1;
        return num.size();
    }
};