class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        unordered_map<char, int> mp_t;

        for (char ch : t)
            mp_t[ch]++;

        int l = 0, r = 0, c = t.length(), size = INT_MAX;
        int min_l = 0; // Track the starting position of the minimum window

        while (r < s.length()) {
            char ele = s[r];

            if (mp_t.find(ele) != mp_t.end()) {
                mp_t[ele]--;
                if (mp_t[ele] >= 0) {
                    c--;
                }
            }

            while (c == 0) {
                if (r - l + 1 < size) {
                    size = r - l + 1;
                    min_l = l; // Update the minimum window's starting position
                }

                char left_char = s[l];
                if (mp_t.find(left_char) != mp_t.end()) {
                    mp_t[left_char]++;
                    if (mp_t[left_char] > 0) {
                        c++;
                    }
                }

                l++;
            }

            r++;
        }

        return size == INT_MAX ? "" : s.substr(min_l, size);
    }
};






