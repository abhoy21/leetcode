class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<int> vgap;
        vector<int> hgap;

        hFences.push_back(m); hFences.push_back(1);
        vFences.push_back(n); vFences.push_back(1);

        sort(vFences.begin(), vFences.end());
        sort(hFences.begin(), hFences.end());

        for(int i = 0; i < hFences.size() - 1; i++){
            for(int j = i+1; j < hFences.size(); j++){
                vgap.push_back(hFences[j] - hFences[i]);
            }
        }

        for(int i = 0; i < vFences.size() - 1; i++){
            for(int j = i+1; j <vFences.size(); j++){
                hgap.push_back(vFences[j] - vFences[i]);
            }
        }

        long long ans = -1;
        sort(vgap.begin(), vgap.end());
        unordered_map<int, int> mp;

        for(int i = 0; i < hgap.size(); i++)
            mp[hgap[i]] = 1;
        
        for(int i = vgap.size()-1; i >= 0; i--){
            if(mp[vgap[i]] == 1){
                long long temp = vgap[i];
                ans = temp * temp;
                ans = ans % 1000000007;
                break;
            }
        }

        return ans;
    }
};