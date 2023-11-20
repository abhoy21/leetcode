class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> when;

        for(auto v: access_times){
            string a = v[0], b = v[1];
            when[a].push_back(stoi(b));
        }

        vector<string> ans;
        for(auto &[x, i]: when){
            sort(i.begin(), i.end());

            int len = i.size();
            bool flag = false;

            for(int j = 0; j + 3 <= len; j++)
                flag |= i[j + 2] < i[j] + 100;
            
            if(flag)
                ans.push_back(x);
        }

        return ans;
    }
};