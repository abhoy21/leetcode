class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string ans = votes[0];
        unordered_map<char, vector<int>> mp;

        for (auto& vote : votes[0]) {
            mp[vote] = vector<int>(ans.size(), 0);
        }

        for (auto& vote : votes) {
            for (int i = 0; i < vote.size(); i++) {
                mp[vote[i]][i]++;
            }
        }

        sort(ans.begin(), ans.end(), [&](char x, char y) {
            for (int i = 0; i < ans.size(); i++) {
                if (mp[x][i] != mp[y][i]) {
                    return mp[x][i] > mp[y][i];
                }
            }
            return x < y;
        });

        return ans;
    }
};
