class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0, c = 0;
        string ans = "";

        while(i < a.length() || i < b.length() || c != 0)
        {
            int x = 0;
            if(i < a.length() && a[a.length() - i - 1] =='1')
                x=1;
            int y = 0;
            if(i < b.length() && b[b.length() - i - 1] == '1')
                y = 1;

            ans = to_string((x+y+c)%2) + ans;
            c = (x+y+c)/2;
            i++;
        }
        return ans;
    }
};