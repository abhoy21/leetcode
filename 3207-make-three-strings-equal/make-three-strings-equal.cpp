class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        int range = min({l1, l2, l3});

        int cnt = 0;
        for(int i = 0; i < range; i++){
            if(s1[i] == s2[i] && s2[i] == s3[i])
                cnt++;
            else
                break;
        }

        return cnt == 0 ? -1 : l1+l2+l3 - 3*cnt;
    }
};